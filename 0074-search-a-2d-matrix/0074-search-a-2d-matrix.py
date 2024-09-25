class Solution(object):
    def searchMatrix(self, matrix, target):
        rows = len(matrix)
        if rows == 0:
            return False  # Early exit if the matrix is empty
        cols = len(matrix[0])  # Assuming all rows have the same number of columns

        low, high = 0, rows * cols - 1  # Define the search space

        while low <= high:
            mid = (low + high) // 2  # Find the midpoint
            row = mid // cols  # Determine the row index
            col = mid % cols   # Determine the column index

            # Check if the target is found
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] < target:
                low = mid + 1  # Search the right half
            else:
                high = mid - 1  # Search the left half

        return False  # Target was not found

