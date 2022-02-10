local p  = require"primecount"
local n1 = 1234
local n2 = "1000000000"
local n3 = 10000
local n4 = 10

print"Prime-counting functions:"

print("pi(".. n1 .."):")
print(p.pi(n1))

print("pi_str(".. n2 .."):")
local ok, result = p.pi_str(n2)
print(result..": "..ok.." digits")

print(n3.."-th prime:")
print(p.nth_prime(n3))

print("phi(".. n3 .. ", " .. n4 .. "):")
print(p.phi(n3, n4))

print(p.version)