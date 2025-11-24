import numpy as np

def square_sum(arr):
    """
    Computes the sum of squares of the elements in the input array.

    Parameters:
    arr (numpy.ndarray): Input array of numbers.

    Returns:
    float: Sum of squares of the elements.
    """
    return np.sum(np.square(arr))

# Example usage
x = np.array([1, 2, 3, 4])
result = square_sum(x)

print("Sum of squares:", result)  # Output: Sum of squares: 30


def test_square_sum():
    # Test with a simple array
    arr1 = np.array([1, 2, 3])
    assert square_sum(arr1) == 14  # 1^2 + 2^2 + 3^2 = 14

    # Test with negative numbers
    arr2 = np.array([-1, -2, -3])
    assert square_sum(arr2) == 14  # (-1)^2 + (-2)^2 + (-3)^2 = 14

    # Test with zeros
    arr3 = np.array([0, 0, 0])
    assert square_sum(arr3) == 0  # 0^2 + 0^2 + 0^2 = 0

    # Test with mixed numbers
    arr4 = np.array([-1, 0, 1])
    assert square_sum(arr4) == 2  # (-1)^2 + 0^2 + 1^2 = 2

    print("All tests passed!")

if __name__ == "__main__":
    test_square_sum()   
