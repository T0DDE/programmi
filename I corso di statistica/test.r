x <- c(3, "bici", 5) # Sto definendo un vettore, e sto facendo una coercizione implicita
print(x)

y <- c(3, 5, 8) # Sto definendo un vettore numerico
print(y)

# H0: mu = 5 
# H1: mu != 5
x <- iris$Sepal.Length # Sto estraendo la colonna Sepal.Length dal dataset iris
n = length(x) # Calcolo la lunghezza del vettore x
x_m <- mean(x) # Calcolo la media dei valori in x
x_s <- sd(x)   # Calcolo la deviazione standard dei valori in x
print(x_m)
print(x_s)

alpha = 0.05 # Livello di significatività
t = (x_m - 5)/(x_s)
quantile = qt(1-alpha/2, n-1) # Calcolo il quantile della distribuzione t di Student

if (abs(t) > quantile) {
  print("Rifiuto H0")
} else {
  print("Non rifiuto H0")
}

p_value = pt(abs(t), n-1)*2 # Calcolo il p-value
print(p_value)

shapiro_test <- shapiro.test(x) # Test di Shapiro-Wilk per la normalità
print(shapiro_test)
if (shapiro_test$p.value < alpha) {
  print("I dati non sono normalmente distribuiti")
} else {
  print("I dati sono normalmente distribuiti")
}