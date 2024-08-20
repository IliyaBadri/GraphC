# GraphC

**GraphC** is a simple C++ application that graphs mathematical functions and saves the output as a BMP (Bitmap) file. It is designed to be easy to use and extend, making it ideal for anyone needing to visualize mathematical functions.

## Features

- Graph any mathematical function by modifying the source code.
- Generate high-quality BMP images of the graph.
- Simple C++ code structure, easy to extend.
- Uses CMake for easy project configuration and building.

## Requirements

- C++11 or higher
- CMake 3.10 or higher

## Installation

1. Clone the repository:

   ```sh
   git clone https://github.com/IliyaBadri/GraphC.git
   cd GraphC
   ```
      

2. Create a build directory and navigate into it:

   ```sh
   mkdir build
   cd build
   ```

3. Generate the build files using CMake:

   ```sh
   cmake ..
   ```

4. Build the project:

   ```sh
   make
   ```

5. Run the program:

   ```sh
   ./GraphC
   ```

## Usage

By default, the program graphs a predefined mathematical function. To graph a different function, modify the `GraphC.cpp` file:

```cpp
// Example: Modify this function to graph a different function
// You can do anything here 
int MathFunction(int x) {
	double xDouble = x; 
	return (int)(30 * ((xDouble - 512) / 100) * ((xDouble - 512) / 100)); 
}
```

After modifying the function, recompile the program and run it again to generate the new graph.

The output will be saved as a BMP file in the same directory as the executable.

## Example Output

![Example Graph](https://raw.githubusercontent.com/IliyaBadri/GraphC/master/example.bmp)

## Contributing

Contributions are welcome! If you have ideas for improvements or new features, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License.
