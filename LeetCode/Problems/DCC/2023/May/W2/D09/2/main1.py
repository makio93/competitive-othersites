# 学習2回目,解説AC

from typing import *;

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        return matrix and [*matrix[0]] + self.spiralOrder([*zip(*matrix[1::])][-1::-1])
