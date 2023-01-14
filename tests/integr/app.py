import sys
import subprocess


def array_integrated_test_empty():
    command = "./build/tests/integr/array_integr_test"
    my_array = []
    sorted_name_list = subprocess.run(
        [command, str(len(my_array)), *[str(i) for i in my_array]],
        capture_output=True,
    )
    print("The exit code was: %d" % sorted_name_list.returncode)
    print("="*30)
    sorted_my_array = sorted_name_list.stdout.decode().split('\n')[:-1]
    if sorted_my_array != sorted(my_array):
        print("ERROR INTEGRATED TEST 1!!!")
        print("="*30)
        sys.exit(-1)
    print("SUCCESS INTEGRATED TEST 1!!!")
    print("="*30)


if __name__ == "__main__":
    array_integrated_test_empty()

