# ⚙️ Métodos Numéricos em C — Newton-Raphson e Gauss-Seidel

Este projeto implementa dois métodos numéricos clássicos em linguagem **C**:

- 🔹 **Método de Newton-Raphson**, para encontrar raízes de equações não lineares (valores de `x` que satisfazem `f(x) = 0`);
- 🔹 **Método de Gauss-Seidel**, para resolver sistemas lineares de equações da forma `Ax = b`.

O código foi desenvolvido com foco em clareza, modularização e aplicação prática dos métodos iterativos.

---

📁 Estrutura do Projeto

├── gauss.c  → Implementação do método de Gauss

├── newton.c  → Implementação do método de Newton-Raphson

├── main.c   → Função principal e menu de seleção

├── projeto.h  → Cabeçalhos e protótipos de funções

├── main.exe  → Executável gerado (Windows)

└── README.md → Este arquivo

⚙️ Funcionalidades
🔹 Método de Newton-Raphson

O método é aplicado sobre a seguinte função:

```c
double f(double x){
double expo = (-x * t) / (2 * l); // expoente do euler
double calc = x / (2 * l);
double radi = (1 / (l * c)) - pow(calc, 2);
if (radi < 0) {
printf("Função não contínua no ponto %lf\n", x);
return NAN;
}
double raiz = sqrt(radi);
double cosseno = raiz * t;
return exp(expo) * cos(cosseno) - 0.01;
}
```

O programa utiliza o método de Newton-Raphson para encontrar as raízes dessa função, tratando casos onde a função deixa de ser contínua.

🔹 Método de Gauss

O programa também implementa o método da eliminação de Gauss para resolver qualquer matriz quadrada de ordem n, realizando:

Leitura da matriz aumentada;

Redução para a forma escalonada;

Retro-substituição para obtenção das soluções.

🧠 Conceitos Envolvidos

Newton-Raphson: técnica iterativa para aproximação de raízes de funções não lineares.

Eliminação de Gauss: método direto para solução de sistemas lineares.

Tratamento de erros numéricos e verificação de continuidade da função.

🛠️ Compilação e Execução

Para compilar todos os módulos:

```bash
gcc main.c newton.c gauss.c -o main.exe -lm
```

Para executar:

```bash
./main.exe
```

💡 Exemplo de Uso

Durante a execução, o programa apresenta um menu que permite escolher entre:

Calcular raízes pelo Método de Newton-Raphson

Resolver um sistema linear pelo Método de Gauss

Os dados necessários são solicitados no terminal, como:

Valores de x, t, l, c para Newton-Raphson

Ordem e coeficientes da matriz para o método de Gauss

👨‍💻 Autor

Desenvolvido por Gabriel Foloni
Repositório: https://github.com/Fologne
👨‍💻 Autor

**[Gabriel Foloni](https://github.com/Fologne)**

Projeto desenvolvido para fins acadêmicos.

┣ 📜 projeto.h # Declarações de funções e constantes

┣ 📜 main.exe # Executável gerado (Windows)

┗ 📜 README.md # Documentação do projeto

