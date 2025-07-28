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
```

### Reshape
```python
np.reshape(a, new_shape)
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
np.arange(0, 5)    # → [0 1 2 3 4]
np.linspace(0, 1, 5)  # → [0.   0.25 0.5  0.75 1.  ]
```