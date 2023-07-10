import csv
import os

files = [f for f in os.listdir('registers') if os.path.isfile(os.path.join('registers', f))]
files.remove('registers.csv')
files.remove('values.csv')

# Read all register definitions from registers.csv
registers = {}
with open('registers/registers.csv', 'r') as f:
    reader = csv.DictReader(f, delimiter=',', skipinitialspace=True)
    for row in reader:
        registers[int(row['address'], 16)] = row
registers = dict(sorted(registers.items()))

# From all region files read bit difinitions
bits = {}
for fname in files:
    with open(f'registers/{fname}', 'r') as f:
        reader = csv.DictReader(f, delimiter=',', skipinitialspace=True)
        for row in reader:
            name = row['type']
            if name not in bits:
                bits[name] = []
            b = row['bits']
            if '-' in b:
                bstart = int(b.split('-')[0])
                bend = int(b.split('-')[1])
            else:
                bstart = int(b)
                bend = int(b)
            bits[name].append({'name':row['name'], 'start':bstart, 'end':bend})
            # Check needed to add fills

# Read all enum definitions from values.csv
values = {}
with open('registers/values.csv', 'r') as f:
    reader = csv.DictReader(f, delimiter=',', skipinitialspace=True)
    for row in reader:
        name = row['type']
        if name not in values:
            values[name] = []
        values[name].append(f'{name}_{row["name"]} = {row["value"]},')

# Create header
device = os.path.basename(os.getcwd())
typeswritten = []
print(device)
with open(f'{device}.h', 'w') as f:
    f.write(f'#ifndef __H_{device.upper()}\n')
    f.write(f'#define __H_{device.upper()}\n')

    for n, vals in values.items():
        f.write(f'\nenum {n} {{\n')
        for v in vals:
            f.write(f'  {v}\n')
        f.write(f'}};\n')

    for a, reg in registers.items():
        f.write(f'\n#define {reg["name"]} R32({reg["address"]})\n')
        if reg["type"] not in bits:
            continue
        print(reg["name"])
        # Check if needed to write type
        if reg["type"] not in typeswritten:
            f.write(f'typedef struct {reg["type"]}_bits_s {{\n')
            index = 0
            reserved = 0
            for b in bits[reg["type"]]:
                if b['start']>index:
                    f.write(f'  uint{reg["size"]}_t _r{reserved} : {b["start"]-index};\n')
                    reserved += 1
                    index += b["start"]-index
                if b["start"]==b["end"]:
                    f.write(f'  uint{reg["size"]}_t {b["name"]} : {b["end"]-b["start"]+1};\n')
                else:
                    f.write(f'  union {{\n')
                    f.write(f'    uint{reg["size"]}_t {b["name"]} : {b["end"]-b["start"]+1};\n')
                    f.write(f'    struct {{\n')
                    for bi in range(b["end"]-b["start"]+1):
                        f.write(f'      uint{reg["size"]}_t {b["name"]}__b{bi} : 1;\n')
                    f.write(f'    }};\n')
                    f.write(f'  }};\n')
                index += b["end"]-b["start"]+1
            if index<int(reg["size"])-1:
                f.write(f'  uint{reg["size"]}_t _r{reserved} : {int(reg["size"])-index};\n')
            f.write(f'}} {reg["type"]}_bits_t;\n')
            typeswritten.append(reg["type"])
        f.write(f'#define {reg["name"]}_bits (*((volatile {reg["type"]}_bits_t *)&{reg["name"]}))\n')

    f.write(f'#endif // __H_{device.upper()}\n')
