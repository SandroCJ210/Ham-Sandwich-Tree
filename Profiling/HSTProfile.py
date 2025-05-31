import cProfile
import pstats
import random
import unittest
from typing import List, Tuple
import numpy as np
import os

from HST import HamSandwichTree

if not os.path.exists('data'):
    os.makedirs('data', exist_ok=True)

class HSTProfile(unittest.TestCase):
    Quantities = [100, 1000, 10000]  
    Runs = 1000                       
    OutputFileName = 'data/stats_hst.csv'
    OutputFileNameSplit = 'data/stats_hst_split.csv'

    @staticmethod
    def write_header(f) -> None:
        f.write('test_case,quantity,method_name,total_time,cumulative_time,per_call_time\n')

    @staticmethod
    def write_row(f, test_case: str, quantity: int, method_name: str, total_time: float,
                   cumulative_time: float, per_call_time: float) -> None:
        f.write(f'{test_case},{quantity},{method_name},{total_time},{cumulative_time},{per_call_time}\n')

    @staticmethod
    def get_running_times(st: pstats.Stats, method_name: str) -> List[Tuple[str, float, float, float]]:
        ps = st.strip_dirs().stats

        def is_method(k):
            return method_name in k[2]

        keys = list(filter(is_method, ps.keys()))
        return [(key[2], ps[key][2], ps[key][3], ps[key][3] / ps[key][1]) for key in keys]

    def test_profile_start_method(self) -> None:
        with open(HSTProfile.OutputFileName, 'w') as f:
            HSTProfile.write_header(f)
            for qty in HSTProfile.Quantities:
                for _ in range(HSTProfile.Runs):
                    tree = HamSandwichTree(is3D=True, quantity=qty, boundary=10)
                    pro = cProfile.Profile()
                    pro.runcall(tree.Start)
                    st = pstats.Stats(pro)

                    for method_name, total_time, cumulative_time, per_call_time in \
                            HSTProfile.get_running_times(st, 'Start'):
                        HSTProfile.write_row(f, 'HST', qty, method_name, total_time, cumulative_time, per_call_time)

                    for method_name, total_time, cumulative_time, per_call_time in \
                            HSTProfile.get_running_times(st, 'CreateTree'):
                        HSTProfile.write_row(f, 'HST', qty, method_name, total_time, cumulative_time, per_call_time)

                    for method_name, total_time, cumulative_time, per_call_time in \
                            HSTProfile.get_running_times(st, 'CreateTreeAux'):
                        HSTProfile.write_row(f, 'HST', qty, method_name, total_time, cumulative_time, per_call_time)

    def test_profile_split_method(self) -> None:
        with open(HSTProfile.OutputFileNameSplit, 'w') as f:
            HSTProfile.write_header(f)
            for qty in HSTProfile.Quantities:
                for _ in range(HSTProfile.Runs):
                    tree = HamSandwichTree(is3D=True, quantity=qty, boundary=10)
                    tree.SpawnRandomPoints(tree.quantity, tree.boundary)
                    root = tree.CreateNode()
                    root.points = tree.points
                    # Queremos medir SplitPoints explícitamente
                    pro = cProfile.Profile()
                    pro.runcall(tree.SplitPoints, root)
                    st = pstats.Stats(pro)

                    for method_name, total_time, cumulative_time, per_call_time in \
                            HSTProfile.get_running_times(st, 'SplitPoints'):
                        HSTProfile.write_row(f, 'HST', qty, method_name, total_time, cumulative_time, per_call_time)

    def test_profile_mixed_operations(self) -> None:
        with open('data/stats_hst_mixed.csv', 'w') as f:
            HSTProfile.write_header(f)
            for qty in HSTProfile.Quantities:
                for _ in range(HSTProfile.Runs):
                    tree = HamSandwichTree(is3D=True, quantity=qty, boundary=10)
                    pro = cProfile.Profile()
                    pro.runcall(tree.Start)
                    st = pstats.Stats(pro)

                    for method_name, total_time, cumulative_time, per_call_time in \
                            HSTProfile.get_running_times(st, 'Start'):
                        HSTProfile.write_row(f, 'HST', qty, method_name, total_time, cumulative_time, per_call_time)

                    for method_name, total_time, cumulative_time, per_call_time in \
                            HSTProfile.get_running_times(st, 'SplitPoints'):
                        HSTProfile.write_row(f, 'HST', qty, method_name, total_time, cumulative_time, per_call_time)

                    for method_name, total_time, cumulative_time, per_call_time in \
                            HSTProfile.get_running_times(st, 'CreateTree'):
                        HSTProfile.write_row(f, 'HST', qty, method_name, total_time, cumulative_time, per_call_time)


# Ejecuta la suite de tests.
suite = unittest.TestLoader().loadTestsFromTestCase(HSTProfile)
unittest.TextTestRunner(verbosity=2).run(suite)
