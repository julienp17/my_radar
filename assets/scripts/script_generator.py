#!/usr/bin/python3

from sys import argv, stderr
from random import sample, randint

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

if len(argv) != 3:
    print("Incorrect nb of arguments", file = stderr)
    quit(1)
try:
    file = open(argv[1], "r")
except OSError:
    print("File couldn't be opened", file = stderr)
    quit(1)
towers = []
planes = []
for line in file:
    infos = line.split()
    new_tower = Tower(infos[1], infos[2], infos[3], infos[len(infos) - 1])
    towers.append(new_tower)
file.close()
i = 0
nb_planes = int(argv[2])
for i in range(nb_planes):
    tower_indexes = sample(range(0, len(towers)), 2)
    plane = Plane(towers[tower_indexes[0]], towers[tower_indexes[1]])
    planes.append(plane)
script = str()
for plane in planes:
    script += (str(plane) + "\n")
for tower in towers:
    script += (str(tower) + "\n")
filename = str(nb_planes) + "_planes_" + str(len(towers)) + "_towers.script"
with open(filename, "w") as file:
    file.write(script)