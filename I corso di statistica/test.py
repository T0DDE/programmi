import numpy as np
def test_function():
    arr = np.array([1, 2, 3])
    assert arr.sum() == 6
    print("Test passed!")
    return arr
if __name__ == "__main__":
    test_function()
    arr = test_function()
    print("Array:", arr)