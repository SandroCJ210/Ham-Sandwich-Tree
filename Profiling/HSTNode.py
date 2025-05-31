from typing import List, Optional
import numpy as np

class HSTNode:
    def __init__(self):
        self.root: Optional['HSTNode'] = None
        self.height: int = 0.0

        self.points: List[np.ndarray] = []  

        self.medianProj: float
        self.direction: np.ndarray = np.zeros(3)  
        self.medianPoint: np.ndarray = np.zeros(3)

        self.parent: Optional['HSTNode'] = None

        self.left: Optional['HSTNode'] = None
        self.right: Optional['HSTNode'] = None

