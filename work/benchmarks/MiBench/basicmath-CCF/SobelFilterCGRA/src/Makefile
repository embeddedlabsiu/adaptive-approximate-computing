# Copyright 2018 Pedro Melgueira
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

FILES=$(wildcard *.c)
EXE=sobel
FLAGS=-std=c99 -g -lm
CC = ../../../../../../scripts/CGRALib/cgracc

all: 
	$(CC) $(FILES) -o $(EXE) $(FLAGS)

clean:
	rm -rf $(OBJS) $(EXE) *.o basicmath_small basicmath_large *.ll CGRAExec m5out *.s *.txt

