import pandas as pd
import matplotlib.pyplot as plt

dimensiones = [10, 50, 100, 500, 1000, 2000, 5000]

for d in dimensiones:
    filename = f"distancias_{d}.csv"
    
    #cargar datos como dataframe
    df = pd.read_csv(filename)
    
    #graficar histograma directamente desde pandas
    ax = df.hist(bins=10, color="skyblue", edgecolor="black", figsize=(8,5))
    plt.suptitle(f"Histograma de distancias - Dimension {d}")

    ax = ax[0][0]
    ax.set_xlabel("Distancia Euclidiana")
    ax.set_ylabel("Frecuencia")
    #para limitar lo que se mostrara en el eje x
    max_val = df.max().values[0]
    ax.set_xlim(0, max_val)
    
    plt.savefig(f"histograma_dim{d}.png", dpi=300)
    plt.close()