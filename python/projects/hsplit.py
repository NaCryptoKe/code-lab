import numpy as np

arr = np.array([[1, 2, 3, 4, 5, 6],
                [7, 8, 9, 10, 11, 12]])

# Split into 3 equal horizontal parts
split_arrays = np.hsplit(arr, 3)

print("Original Array:")
print(arr)
print("\nSplit Arrays:")
for i, sub_array in enumerate(split_arrays):
    print(f"Sub-array {i}:")
    print(sub_array)

arr = np.array([[1, 2, 3, 4, 5],
                [6, 7, 8, 9, 10]])

try:
    # This will raise an error because 5 columns cannot be split into 3 equal parts
    split_arrays = np.hsplit(arr, 3)
    print(split_arrays)
except ValueError as e:
    print(f"Error: {e}")

