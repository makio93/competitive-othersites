# 解説AC1(Python3解)

from typing import *;

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        return matrix and [*matrix[0]] + self.spiralOrder([*zip(*matrix[1:])][::-1])
