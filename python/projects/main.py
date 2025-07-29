import numpy as np

a = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])

b = np.nonzero(a < 5)
print(b)
print("Printed B")
print()

list_of_coordinates= list(zip(b[0], b[1]))

for coord in list_of_coordinates:
    print(coord)

print("Printed coord")
print()

print(a[b])

not_there = np.nonzero(a == 42)
print(not_there)