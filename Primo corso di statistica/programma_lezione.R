x <- c(3, "bici", 5) 
# Sto definendo un vettore, e sto facendo una coercizione implicita
print(x)

y <- c(3, 5, 8) # Sto definendo un vettore numerico
print(y)

r <- rnorm(4000)
# nelle distribuzioni, d: deniìsity, p: distribution function, q: quantile
# e r: random
# quindi per esempio: dnorm, dchisq, pnorm, rnorm, 
# esempio con la t di student: t <- qt(1-alpha/2, n-1)

# ad esempio a qnorm do la probabilità, e mi da il corrispondente 
# valore della x. pnorm il contrario, do q e mi restituiscce la probabilità.

# H0: mu = 5 
# H1: mu != 5

x <- iris$Sepal.Length 
# Sto estraendo la colonna Sepal.Length dal dataset iris

n = length(x) # Calcolo la lunghezza del vettore x
x_m <- mean(x) # Calcolo la media dei valori in x
x_s <- sd(x)   # Calcolo la deviazione standard dei valori in x

alpha = 0.05 # Livello di significatività
t = (x_m - 5)/(x_s/sqrt(n))
# sto assumendo che la media campionaria sia distribuita normalmente
# quindi divido per la radice di n la deviazione standard
quantile = qt(1-alpha/2, n-1) 
# Calcolo il quantile della distribuzione t di Student)

if (abs(t) > quantile) {
  print("Rifiuto H0")
} else {
  print("Non rifiuto H0")
}

p_value = (1-pt(abs(t),n-1))*2 # Calcolo il p-value
print(p_value)

shapiro_test <- shapiro.test(x) # Test di Shapiro-Wilk per la normalità
print(shapiro_test)
if (shapiro_test$p.value < alpha) {
  print("I dati non sono normalmente distribuiti")
} else {
  print("I dati sono normalmente distribuiti")
}

# nota: il shapiro test sarebbe stato da fare prima.

t.test(x,mu=5, var.equal=TRUE) 
# questo fa quello che abbiamo fatto manualmente fino a qui.












