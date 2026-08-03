import pandas as pd
import matplotlib.pyplot as plt


data = pd.read_csv("quickselect_runtime.csv")


plt.figure(figsize=(8, 5))
plt.plot(data["Dataset_Size"], data["Runtime_ms"], marker="o")


plt.xlabel("Dataset Size (n)")
plt.ylabel("Average Runtime (ms)")
plt.title("Quickselect Average Runtime")

plt.grid(True)


plt.savefig("quickSelect.png", dpi=300)


plt.show()