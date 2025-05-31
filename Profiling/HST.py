from typing import List, Optional
from .HSTNode import HSTNode
import numpy as np
import random
import math


class HamSandwichTree:
    def __init__(self, is3D: bool, quantity: int = 100, boundary: float = 10):
        self.is3D = is3D    
        self.quantity = quantity
        self.boundary = boundary
        self.points: List[np.ndarray] = [] 
        self.root: Optional[HSTNode] = None
    #main
    def Start(self):
        random.seed()
        self.SpawnRandomPoints(self.quantity, self.boundary)
        self.CreateTree()

    def CreateTree(self):
        self.root = self.CreateNode()
        self.root.points = self.points
        self.CreateTreeAux(self.root)

    def CreateTreeAux(self, node: HSTNode):
        if len(node.points) < 5:
            return
        self.SplitPoints(node)
        self.CreateTreeAux(node.left)
        self.CreateTreeAux(node.right)

    def CreateNode(self, parent: Optional[HSTNode] = None) -> HSTNode:
        newNode = HSTNode()
        newNode.root = self.root
        newNode.parent = parent
        if parent is not None:
            newNode.height = parent.height + 1
        return newNode

    def SpawnRandomPoints(self, quantity: int, boundary: float):
        for i in range(quantity):
            x = random.uniform(-boundary, boundary)
            y = random.uniform(-boundary, boundary)
            z = 0.0
            if self.is3D:
                z = random.uniform(-boundary, boundary)
                
            pos = np.array([x, y, z], dtype=float)
            self.points.append(pos)

    # HAM SANDWICH ALGORITHM 
    def SplitPoints(self, node: HSTNode):
        theta = random.uniform(0, math.pi)
        phi = random.uniform(0, math.pi)

        if self.is3D:
            direction = np.array([
                math.cos(theta) * math.sin(phi),
                math.sin(theta) * math.sin(phi),
                math.cos(phi)
            ], dtype=float)
        else:
            direction = np.array([
                math.cos(theta),
                math.sin(theta),
                0.0
            ], dtype=float)

        projections = [{'point': p, 'projection': np.dot(p, direction)} for p in node.points]
        projections.sort(key=lambda e: e['projection'])

        median_index = len(projections) // 2
        medianPoint = projections[median_index]['point']
        medianProj = projections[median_index]['projection']

        rightPoints: List[np.ndarray] = []
        leftPoints: List[np.ndarray] = []

        for element in projections:
            if element['projection'] >= medianProj:
                rightPoints.append(element['point'])
            else:
                leftPoints.append(element['point'])

        node.left = self.CreateNode(node)
        node.right = self.CreateNode(node)
        node.left.points = leftPoints
        node.right.points = rightPoints
        node.direction = direction
        node.medianPoint = medianPoint
        node.medianProj = medianProj



