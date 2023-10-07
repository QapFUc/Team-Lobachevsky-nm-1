from pynm import *

def main():
    '''main function'''

    libc = CDLL("bazel-out/src/core/nmlib.so")

    # config requiered (user data)
    cfg = ()

    result = run_task(libc, config=cfg)

    # func that generate python result from run_task result

if __name__ == '__main__':
    main()