import networkx as nx
import matplotlib.pyplot as plt
import numpy as np

# Создаем пустой многоканальный направленный граф
G = nx.MultiDiGraph()

# Добавляем все узлы
nodes = range(8)
G.add_nodes_from(nodes)

# Добавляем ребра
matrix = [
    [np.inf, 50, 60, 20, 30, 70, 40, 80],
    [40, np.inf, 20, 70, 50, 60, 90, 30],
    [30, 40, np.inf, 80, 20, 50, 60, 70],
    [70, 30, 90, np.inf, 40, 20, 50, 60],
    [20, 60, 70, 50, np.inf, 30, 80, 40],
    [80, 50, 40, 30, 60, np.inf, 20, 70],
    [90, 20, 30, 60, 70, 80, np.inf, 50],
    [50, 70, 20, 40, 90, 60, 30, np.inf]
]

for i in range(len(matrix)):
    for j in range(len(matrix[i])):
        if matrix[i][j] != np.inf:
            G.add_edge(i, j, weight=matrix[i][j])

# Выводим граф
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, node_color='lightblue', font_size=12, node_size=500)
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

plt.axis('off')
plt.title("Граф")
plt.show()
