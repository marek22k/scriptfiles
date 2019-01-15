v = c()

for(i in 0:100)
	v = c(v, i*i/2+i/2) # i^2/2+n/2 = i*i/2+i/2

print(v)
png(file = "triangle_numbers.png")
plot(v, type = "l", col = "black", xlab = "x", ylab = "n", main = "x=n^2/2+n/2")

dev.off()