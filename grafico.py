import pandas as pd
import matplotlib.pyplot as plt
import os

ficheiros = {
    'Linear Iterativa': 'pior_caso_linear_iterativa.csv',
    'Linear Recursiva': 'pior_caso_linear_recursiva.csv',
    'Sentinela Iterativa': 'pior_caso_sentinela_iterativa.csv',
    'Sentinela Recursiva': 'pior_caso_sentinela_recursiva.csv',
    'Binária Iterativa': 'pior_caso_binaria_iterativa.csv',
    'Binária Recursiva': 'pior_caso_binaria_recursiva.csv',
    'Ternária Iterativa': 'pior_caso_ternaria_iterativa.csv',
    'Ternária Recursiva': 'pior_caso_ternaria_recursiva.csv'
}

def ler_csv_inteligente(caminho):
    for enc in ['utf-16', 'utf-16-le', 'utf-8', 'latin1']:
        for sep in [',', ';', '\t']:
            try:
                df = pd.read_csv(caminho, encoding=enc, sep=sep)
                if df.shape[1] >= 2 and len(df) > 0:
                    return df
            except Exception:
                continue
    return None

# --- 1. GRÁFICO GERAL ---
plt.figure(figsize=(12, 6))
for nome, arquivo in ficheiros.items():
    if os.path.exists(arquivo):
        df = ler_csv_inteligente(arquivo)
        if df is not None:
            df.columns = [str(c).replace('\x00', '').strip() for c in df.columns]
            x = pd.to_numeric(df.iloc[:, 0].astype(str).str.replace('\x00', ''), errors='coerce')
            y = pd.to_numeric(df.iloc[:, 1].astype(str).str.replace('\x00', ''), errors='coerce')
            m = x.notna() & y.notna()
            plt.plot(x[m], y[m], label=nome, linewidth=2)

plt.title('Comparação Geral dos 8 Algoritmos de Busca (Escala Linear)', fontsize=13, fontweight='bold')
plt.xlabel('Tamanho do Vetor (N)', fontsize=11)
plt.ylabel('Tempo (Nanosegundos)', fontsize=11)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend(loc='upper left', fontsize=9)
plt.tight_layout()
plt.savefig('grafico_comparativo_final.png', dpi=300)
plt.close()

# --- 2. GRÁFICO ZOOM LOGARÍTMICO (Apenas Binária e Ternária) ---
plt.figure(figsize=(12, 6))
eficientes = ['Binária Iterativa', 'Binária Recursiva', 'Ternária Iterativa', 'Ternária Recursiva']

for nome in eficientes:
    arquivo = ficheiros[nome]
    if os.path.exists(arquivo):
        df = ler_csv_inteligente(arquivo)
        if df is not None:
            df.columns = [str(c).replace('\x00', '').strip() for c in df.columns]
            x = pd.to_numeric(df.iloc[:, 0].astype(str).str.replace('\x00', ''), errors='coerce')
            y = pd.to_numeric(df.iloc[:, 1].astype(str).str.replace('\x00', ''), errors='coerce')
            m = x.notna() & y.notna()
            plt.plot(x[m], y[m], label=nome, linewidth=2)

plt.title('Detalhamento do Desempenho: Buscas Logarítmicas O(log N)', fontsize=13, fontweight='bold')
plt.xlabel('Tamanho do Vetor (N)', fontsize=11)
plt.ylabel('Tempo (Nanosegundos)', fontsize=11)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend(loc='upper left', fontsize=9)
plt.tight_layout()
plt.savefig('grafico_zoom_logaritmico.png', dpi=300)
plt.close()

print("Sucesso! As duas imagens ('grafico_comparativo_final.png' e 'grafico_zoom_logaritmico.png') foram geradas.")