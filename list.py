Python 3.14.2 (tags/v3.14.2:df79316, Dec  5 2025, 17:18:21) [MSC v.1944 64 bit (AMD64)] on win32
Enter "help" below or click "Help" above for more information.
import pandas as pd
data = [100 , 200 , 300 , 400 , 500]
series = pd.Series(data , index = ['a' , 'b' , 'c' , 'd' , 'e'])
series
a    100
b    200
c    300
d    400
e    500
dtype: int64
series.loc[e]
Traceback (most recent call last):
  File "<pyshell#4>", line 1, in <module>
    series.loc[e]
NameError: name 'e' is not defined
series.loc['e']
np.int64(500)
series.loc['c']
np.int64(300)
series.loc[1]
Traceback (most recent call last):
  File "C:\Users\HP\AppData\Roaming\Python\Python314\site-packages\pandas\core\indexes\base.py", line 3641, in get_loc
    return self._engine.get_loc(casted_key)
  File "pandas/_libs/index.pyx", line 168, in pandas._libs.index.IndexEngine.get_loc
  File "pandas/_libs/index.pyx", line 176, in pandas._libs.index.IndexEngine.get_loc
  File "pandas/_libs/index.pyx", line 583, in pandas._libs.index.StringObjectEngine._check_type
KeyError: 1

The above exception was the direct cause of the following exception:

Traceback (most recent call last):
  File "<pyshell#7>", line 1, in <module>
    series.loc[1]
  File "C:\Users\HP\AppData\Roaming\Python\Python314\site-packages\pandas\core\indexing.py", line 1207, in __getitem__
    return self._getitem_axis(maybe_callable, axis=axis)
  File "C:\Users\HP\AppData\Roaming\Python\Python314\site-packages\pandas\core\indexing.py", line 1449, in _getitem_axis
    return self._get_label(key, axis=axis)
  File "C:\Users\HP\AppData\Roaming\Python\Python314\site-packages\pandas\core\indexing.py", line 1399, in _get_label
    return self.obj.xs(label, axis=axis)
  File "C:\Users\HP\AppData\Roaming\Python\Python314\site-packages\pandas\core\generic.py", line 4253, in xs
    loc = index.get_loc(key)
  File "C:\Users\HP\AppData\Roaming\Python\Python314\site-packages\pandas\core\indexes\base.py", line 3648, in get_loc
    raise KeyError(key) from err
KeyError: 1
>>> series.iloc[1]
np.int64(200)
>>> series[0]
Traceback (most recent call last):
  File "C:\Users\HP\AppData\Roaming\Python\Python314\site-packages\pandas\core\indexes\base.py", line 3641, in get_loc
    return self._engine.get_loc(casted_key)
  File "pandas/_libs/index.pyx", line 168, in pandas._libs.index.IndexEngine.get_loc
  File "pandas/_libs/index.pyx", line 176, in pandas._libs.index.IndexEngine.get_loc
  File "pandas/_libs/index.pyx", line 583, in pandas._libs.index.StringObjectEngine._check_type
KeyError: 0

The above exception was the direct cause of the following exception:

Traceback (most recent call last):
  File "<pyshell#9>", line 1, in <module>
    series[0]
  File "C:\Users\HP\AppData\Roaming\Python\Python314\site-packages\pandas\core\series.py", line 959, in __getitem__
    return self._get_value(key)
  File "C:\Users\HP\AppData\Roaming\Python\Python314\site-packages\pandas\core\series.py", line 1046, in _get_value
    loc = self.index.get_loc(label)
  File "C:\Users\HP\AppData\Roaming\Python\Python314\site-packages\pandas\core\indexes\base.py", line 3648, in get_loc
    raise KeyError(key) from err
KeyError: 0
>>> series[['a' , 'e']]
a    100
e    500
dtype: int64
