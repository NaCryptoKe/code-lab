# NumPy (Numerical Python)

NumPy is a powerful Python library for numerical computing. It’s like the buffed-up, protein-shake version of Python lists.

## Importing NumPy

```python
import numpy as np  # 'np' is the community standard alias
```

## NumPy Arrays

NumPy arrays are like Python lists, but faster, more compact, and way better for math.
They are:

- 0-indexed
- Homogeneous (same data type)
- Fixed-size (after creation)

You can slice them like Python lists, and they are mutable.

Creating an array:
```python
a = np.array([1, 2, 3])
```

Array Dimensions:

- 0D: Scalar → np.array(5)
- 1D: Vector → np.array([1, 2, 3])
- 2D: Matrix → np.array([[1, 2], [3, 4]])
- 3D: Tensor → np.array([[[1], [2]], [[3], [4]]])

## Common Attributes & Methods
```python
a.ndim    # Number of dimensions
a.shape   # Tuple showing size of each axis
a.size    # Total number of elements
a.dtype   # The datatype being stored in the array

np.nonzero()    # Returns a value of the co-ordiantes that meet a certain criteria
```

### Reshape
```python
np.reshape(a, new_shape)

a = np.arange(6)

print(a)
[0 1 2 3 4 5]

b = a.reshape(3, 2)

print(b)
[[0 1]
 [2 3]
 [4 5]]
```

### Sorting
```python
np.sort(a)  # Returns sorted copy
np.argsort(a)  # Returns indices that would sort the array
```

### Combining Arrays
```python
np.concatenate((a1, a2), axis=0)
```

### Creating array quickly
```python
np.zeros(3)        # → [0. 0. 0.]
np.ones(3)         # → [1. 1. 1.]
np.empty(2)        # → [3.14, 4.12] gives you random 2 valued array
np.arange(0, 5)    # → [0 1 2 3 4]
np.linspace(0, 1, 5)  # → [0.0   0.25 0.5  0.75 1.0 ]
```

## Converting 1D to 2D (Adding New Axis)

### np.newaxis

`np.newaxis` is used to increase the dimension of an array by adding a new axis. It can transform a 1D array into a 2D array, a 2D into a 3D, and so on.

```python
import numpy as np

a = np.array([1, 2, 3, 4, 5, 6])
print(f"Original array 'a': {a}")
print(f"Shape of 'a': {a.shape}")
# Output: (6,)

# Add a new axis as the first dimension (row vector)
a2 = a[np.newaxis, :]
print(f"\nArray 'a2' after a[np.newaxis, :]:\n{a2}")
print(f"Shape of 'a2': {a2.shape}")
# Output: (1, 6)

# Add a new axis as the second dimension (column vector)
a3 = a[:, np.newaxis]
print(f"\nArray 'a3' after a[:, np.newaxis]:\n{a3}")
print(f"Shape of 'a3': {a3.shape}")
# Output: (6, 1)
```

### np.expand_dims()

`np.expand_dims()` provides the same functionality as `np.newaxis` but offers a more explicit way to specify the position where the new axis should be inserted using the `axis` parameter.

```python
import numpy as np

a = np.array([1, 2, 3, 4, 5, 6])
print(f"Original array 'a': {a}")
print(f"Shape of 'a': {a.shape}")
# Output: (6,)

# Add a new axis at axis 1 (making it a column vector)
b = np.expand_dims(a, axis=1)
print(f"\nArray 'b' after np.expand_dims(a, axis=1):\n{b}")
print(f"Shape of 'b': {b.shape}")
# Output: (6, 1)

# Add a new axis at axis 0 (making it a row vector)
c = np.expand_dims(a, axis=0)
print(f"\nArray 'c' after np.expand_dims(a, axis=0):\n{c}")
print(f"Shape of 'c': {c.shape}")
# Output: (1, 6)
```

## Slicing and Indexing

NumPy arrays can be sliced and indexed similarly to Python lists, but with extensions for multiple dimensions.

```python
import numpy as np

a = np.array([[1, 2, 3, 4],
              [5, 6, 7, 8],
              [9, 10, 11, 12]])

print(f"Original array 'a':\n{a}")

# Basic Slicing:
# Get the first row
print(f"\nFirst row: {a[0, :]}")
# Get the second column
print(f"Second column: {a[:, 1]}")
# Get sub-array (rows 0 to 1, columns 1 to 2)
print(f"Sub-array a[0:2, 1:3]:\n{a[0:2, 1:3]}")

# np.nonzero() for finding indices
# Find coordinates where elements are less than 5
b = np.nonzero(a < 5)
# Output 'b' is a tuple of arrays, representing the row and column coordinates
# of the elements satisfying the condition.
# Example: ([0, 0, 0, 0] rows, [0, 1, 2, 3] columns) corresponds to values 1, 2, 3, 4.
print(f"\nResult of np.nonzero(a < 5): {b}")

# Fancy Indexing / Boolean Indexing
# This uses the output of np.nonzero (or a boolean array) to directly select elements.
print(f"Elements from 'a' where 'a < 5': {a[b]}")
# Output: [1 2 3 4]
```

## Stacking Arrays (Concatenation)

NumPy provides functions to stack arrays along different axes.

```python
import numpy as np

a = np.array([[1, 2], [3, 4]])
b = np.array([[5, 6], [7, 8]])

print(f"Array 'a':\n{a}")
print(f"Array 'b':\n{b}")

# np.vstack(): Stacks arrays vertically (row-wise, along axis 0)
# All arrays must have the same number of columns.
stacked_v = np.vstack((a, b)) # Note the tuple `(a, b)`
print(f"\nnp.vstack((a, b)):\n{stacked_v}")
# Output:
# [[1 2]
#  [3 4]
#  [5 6]
#  [7 8]]

# np.hstack(): Stacks arrays horizontally (column-wise, along axis 1)
# All arrays must have the same number of rows.
stacked_h = np.hstack((a, b)) # Note the tuple `(a, b)`
print(f"\nnp.hstack((a, b)):\n{stacked_h}")
# Output:
# [[1 2 5 6]
#  [3 4 7 8]]
```

## Splitting Arrays

NumPy offers functions to split arrays into multiple sub-arrays.

### np.hsplit()

`np.hsplit()` splits an array into multiple sub-arrays horizontally (column-wise). It's equivalent to np.split(ary, ..., axis=1).

Parameters:
- ary: The input NumPy array to be split. (Required).
- indices_or_sections: Determines how the array will be split:
    - An integer (N): Attempts to divide the array into N equally sized sub-arrays along the horizontal axis (columns). Crucially, the number of columns in ary must be perfectly divisible by N; otherwise, a ValueError will be raised.
    - A 1-D array (or list) of sorted integers: These integers represent the column indices before which a split should occur. This allows for uneven splits. For example, [2, 5] would split the array before column 2, then before column 5.

```python
import numpy as np

arr = np.array([[1, 2, 3, 4, 5, 6],
                [7, 8, 9, 10, 11, 12]])

print(f"Original Array for hsplit:\n{arr}")

# Example 1: Split into 3 equal horizontal parts (6 columns / 3 = 2 columns per sub-array)
split_equal = np.hsplit(arr, 3)
print(f"\nnp.hsplit(arr, 3):")
for i, sub_array in enumerate(split_equal):
    print(f"  Sub-array {i}:\n{sub_array}")

# Example 2: Split at specific column indices [2, 4]
split_indices = np.hsplit(arr, [2, 4])
print(f"\nnp.hsplit(arr, [2, 4]):")
for i, sub_array in enumerate(split_indices):
    print(f"  Sub-array {i}:\n{sub_array}")
```

### np.vsplit()

`np.vsplit()` splits an array into multiple sub-arrays vertically (row-wise). It's equivalent to `np.split(ary, ..., axis=0)`.

```python
import numpy as np

arr_v = np.array([[1, 2, 3],
                  [4, 5, 6],
                  [7, 8, 9],
                  [10, 11, 12]])

print(f"\nOriginal Array for vsplit:\n{arr_v}")

# Example: Split into 2 equal vertical parts (4 rows / 2 = 2 rows per sub-array)
split_v_equal = np.vsplit(arr_v, 2)
print(f"\nnp.vsplit(arr_v, 2):")
for i, sub_array in enumerate(split_v_equal):
    print(f"  Sub-array {i}:\n{sub_array}")
```

### np.dsplit() (for 3D arrays)

`np.dsplit()` splits an array along the third axis (depth-wise). It's equivalent to np.split(ary, ..., axis=2).

## NumPy Basic Arithmetic and Broadcasting

NumPy allows element-wise arithmetic operations (`+, -, *, /`) between arrays. For these operations to work directly, arrays must generally have the same shape, or be compatible via a concept called **Broadcasting**.

```python
import numpy as np

arr1 = np.array([[1, 2], [3, 4]])
arr2 = np.array([[5, 6], [7, 8]])

print(f"arr1:\n{arr1}")
print(f"arr2:\n{arr2}")

# Element-wise addition
print(f"\narr1 + arr2:\n{arr1 + arr2}")
# Element-wise multiplication
print(f"arr1 * arr2:\n{arr1 * arr2}")

# Broadcasting: Performing an operation between an array and a scalar (or an array of compatible shape)
# The scalar is "broadcast" across the entire array.
print(f"\narr1 * 10:\n{arr1 * 10}")
# Output:
# [[10 20]
#  [30 40]]

# Broadcasting with arrays of different but compatible shapes
# (Rules are more complex but allow operations like adding a 1D array to each row/column of a 2D array)
# Example: Adding a 1D array to each row of a 2D array
row_to_add = np.array([100, 200])
print(f"\narr1 + row_to_add:\n{arr1 + row_to_add}")
# Output:
# [[101 202]
#  [103 204]]
```

### np.sum()
`np.sum()` calculates the sum of array elements. By default, it sums all elements. The `axis` parameter allows summing along a specific dimension.

```python
import numpy as np

arr = np.array([[1, 2, 3],
                [4, 5, 6]])

print(f"Array for sum:\n{arr}")

# Sum of all elements
print(f"\nnp.sum(arr): {np.sum(arr)}")
# Output: 21 (1+2+3+4+5+6)

# Sum along axis=0 (columns)
print(f"np.sum(arr, axis=0): {np.sum(arr, axis=0)}")
# Output: [5 7 9] (1+4, 2+5, 3+6)

# Sum along axis=1 (rows)
print(f"np.sum(arr, axis=1): {np.sum(arr, axis=1)}")
# Output: [ 6 15] (1+2+3, 4+5+6)
```