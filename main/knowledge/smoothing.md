---
priority: 3rd
status: dormant
url: 
category: 
parent: 
children: 
link_action: 
link_topic: 
link_project: 
link_course: 
link_notes: 
---
Up Level: (parent:: [Statistics](Statistics.md))


### Reference

[Gaussian smoothing](https://influentialpoints.com/Training/gaussian_smoothing.htm)

https://towardsdatascience.com/gaussian-smoothing-in-time-series-data-c6801f8a4dc3

[Gaussian Smoothing](https://homepages.inf.ed.ac.uk/rbf/HIPR2/gsmooth.htm)

### ❓ Question

- [x]  How to reset a point value in Gaussian smoothing? multiplication of two curve, one is raw data when the other is gaussian kernel.

---

# by running average

cons

- ignores what value of y each frequency corresponds to.
- to decide upon how many values to use for your smoothing function
- run into difficulties with the ends of a sample distribution

# by jittering

The graph below shows the result of applying 5000 random normal errors to each of the calcium concentrations we showed above

![Untitled](smoothing%20194f653fd61949729f0035c1e95d27e9/Untitled.png)

![Untitled](smoothing%20194f653fd61949729f0035c1e95d27e9/Untitled%201.png)

## Gaussian smoothing

![Untitled](smoothing%20194f653fd61949729f0035c1e95d27e9/Untitled%202.png)

![Untitled](smoothing%20194f653fd61949729f0035c1e95d27e9/Untitled%203.png)

### code example

```python
from datetime import datetime
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

owid_url = 'https://raw.githubusercontent.com/owid/covid-19-data/master/public/data/owid-covid-data.csv'

df = pd.read_csv(owid_url)

# filtering for Nepal data
npl = df[df['iso_code'] == 'NPL']

# converting string type to datetime 
npl['date'] = pd.to_datetime(npl['date'])

plt.plot(npl['date'],npl['new_cases'])

# calculating Gaussian kernel values 
npl['gkv'] = np.exp(
    -(((npl['date'] - datetime(2020, 10, 27)).apply(lambda x: x.days)) ** 2) / (2 * (2 ** 2))
)

##  standardize the kernel values 
npl['gkv'] = npl['gkv'] / npl['gkv'].sum()
(npl['new_cases'] * npl['gkv']).sum()

## smoothing for all the data points
smoothed_cases = []
for date in sorted(npl['date']):
    npl['gkv'] = np.exp(
        -(((npl['date'] - date).apply(lambda x: x.days)) ** 2) / (2 * (2 ** 2))
    )
    npl['gkv'] /= npl['gkv'].sum()
    smoothed_cases.append(round(npl['new_cases'] * npl['gkv']).sum())

npl['smoothed_new_cases'] = smoothed_cases

plt.plot(npl['date'],npl['smoothed_new_cases'])
plt.show()
```

output

![Untitled](smoothing%20194f653fd61949729f0035c1e95d27e9/Untitled%204.png)

## Example of a Gaussian convolution matrix

![Untitled](smoothing%20194f653fd61949729f0035c1e95d27e9/Untitled%205.png)

### How to get this convolution matrix

Above figure shows a suitable integer-valued convolution kernel that approximates a Gaussian with a  of 1.0. It is not obvious how to pick the values of the mask to approximate a Gaussian. One could use the value of the Gaussian at the centre of a pixel in the mask, but this is not accurate because the value of the Gaussian varies non-linearly across the pixel. 

- We integrated the value of the Gaussian over the whole pixel (by summing the Gaussian at 0.001 increments).
- The integrals are not integers: we rescaled the array so that the corners had the value 1. Finally, the 273 is the sum of all the values in the mask.