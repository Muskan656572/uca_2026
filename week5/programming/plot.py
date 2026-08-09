import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("results.csv")

plt.plot(data["Size"], data["Random"], label="Random")
plt.plot(data["Size"], data["Ascending"], label="Ascending")
plt.plot(data["Size"], data["Descending"], label="Descending")

plt.xlabel("Input Size")
plt.ylabel("Execution Time (seconds)")
plt.title("Heap Sort Performance")

plt.legend()
plt.grid()

plt.savefig("heap_sort_graph.png")

plt.show()