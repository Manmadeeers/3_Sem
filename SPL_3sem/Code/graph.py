import networkx as nx
import matplotlib.pyplot as plt
import random

# Create directed graph with 9 nodes
G = nx.DiGraph()
nodes = range(9)
G.add_nodes_from(nodes)

# Add weighted edges between all pairs of nodes
for i in range(9):
    for j in range(i+1, 9):
        weight = random.random()
        G.add_edge(i, j, weight=weight)
        # Add reverse edge with potentially different weight
        G.add_edge(j, i, weight=random.random())

# Layout
pos = nx.spring_layout(G)

# Draw nodes
nx.draw_networkx_nodes(G, pos, node_color='lightblue', node_size=500)

# Draw edges with labels
edge_labels = nx.get_edge_attributes(G,'weight')
nx.draw_networkx_edges(G, pos, edge_color='gray', arrows=True)
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

# Draw labels
nx.draw_networkx_labels(G, pos, font_size=10)

plt.axis('off') 
plt.show()
