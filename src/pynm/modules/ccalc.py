from ctypes import *

class tableRow(Structure):
    '''Adapter for C structure from nmlib'''
    _fields_ =   [("xi", c_float),
                  ("vi", c_float),
                  ("v2i", c_float),
                  ("viv2i", c_float),
                  ("LE", c_float),
                  ("hi", c_float),
                  ("C1", c_uint32),
                  ("C2", c_uint32),
                  ("ui", c_float),
                  ("uvi", c_float)]
    
def run_task(libc, task_name="TEST_TASK_A", config=()):
    '''libc is a loaded shared lib; config is a tuple with all config parameters in a strictly defined order'''

    task = c_char_p(task_name)

    x_min = c_float(config[0])
    x_max = c_float(config[1])
    x_0 = c_float(config[2])
    u_0 = c_float(config[3])
    step = c_float(config[4])
    N_max = c_uint32(config[5])
    LEC = c_bool(config[6])
    eps = c_float(config[7])

    rows_count = POINTER(c_uint32)
    libc.run_from_python.restype = POINTER(tableRow)

    result = POINTER(tableRow)
    result = libc.run_from_python(task,
                                  x_min,
                                  x_max,
                                  x_0,
                                  u_0,
                                  step,
                                  N_max,
                                  LEC,
                                  eps,
                                  rows_count)
    
    return (rows_count.contents, result)


