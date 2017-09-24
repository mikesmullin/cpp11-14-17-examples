%: %.cc
	/usr/bin/g++-7 -std=c++1z -O0 -S $< -o $@
