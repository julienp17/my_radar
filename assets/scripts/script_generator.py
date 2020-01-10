#!/usr/bin/python3

from sys import argv, stderr
from random import sample, randint, shuffle

USAGE = """USAGE:
./script_generator  nb_planes nb_towers

nb_planes           integer between 0 and infinity
nb_towers           integer between 2 and 35"""

class Tower:

    def __init__(self, x: int, y: int, radius: int, country: str):
        self.pos = (x, y)
        self.radius = radius
        self.country = country

    def __str__(self):
        return "T {} {} {} // {}".format(
                str(self.pos[0]),
                str(self.pos[1]),
                str(self.radius),
                self.country)

class Plane:

    def __init__(self, departure_tower: Tower, arrival_tower: Tower):
        self.departure = departure_tower.pos
        self.arrival = arrival_tower.pos
        self.departure_country = departure_tower.country
        self.arrival_country = arrival_tower.country
        self.speed = randint(3, 6)
        self.delay = randint(0, 20)

    def __str__(self):
        return "A {} {} {} {} {} {} // {} -> {}".format(
                str(self.departure[0]),
                str(self.departure[1]),
                str(self.arrival[0]),
                str(self.arrival[1]),
                str(self.speed),
                str(self.delay),
                self.departure_country,
                self.arrival_country)

if len(argv) == 2 and (argv[1] == "-h" or argv[1] == "--help"):
    print(USAGE)
    quit(0)
if len(argv) != 3:
    print("Incorrect number of arguments\n\n" + USAGE, file = stderr)
    quit(1)
nb_planes = int(argv[1])
nb_towers = int(argv[2])
if nb_planes < 0 or (nb_towers < 2 or nb_towers > 35):
    print(USAGE, file = stderr)
    quit(1)
towers = []
planes = []
try:
    file = open(".towers_pos", "r")
except OSError:
    print("File couldn't be opened", file = stderr)
    quit(1)
for line in file:
    infos = line.split()
    new_tower = Tower(infos[1], infos[2], infos[3], infos[len(infos) - 1])
    towers.append(new_tower)
file.close()
shuffle(towers)
towers = towers[:nb_towers]
i = 0
for i in range(nb_planes):
    tower_indexes = sample(range(0, len(towers)), 2)
    plane = Plane(towers[tower_indexes[0]], towers[tower_indexes[1]])
    planes.append(plane)
filename = argv[1] + "_planes_" + argv[2] + "_towers.script"
with open(filename, "w") as file:
    for plane in planes:
        file.write(str(plane) + "\n")
    for tower in towers:
        file.write(str(tower) + "\n")
quit(0)