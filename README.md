# Kruskal’s MST Historical Site Mapper

### Author: 
Sreeram Kondapalli

### Description:
Kruskal’s MST Historical Site Mapper is an intricate piece of software designed to traverse historical sites efficiently utilizing Kruskal's Minimum Spanning Tree (MST) algorithm paired with a disjoint set data structure. The application meticulously processes input representing various historical sites and their distances, producing an optimal map of the journey.

### Features:
- **Dynamic Array Creation**: Constructs arrays dynamically, managing vertices and edges which represent historical sites and the routes between them.
  
- **Input Processing**: Processes each line of input to craft objects that represent sites and routes, creating a holistic representation of the historical journey.
  
- **Adaptability**: Seamlessly integrates new sites into the existing data structure.
  
- **Edge Construction**: Precisely crafts edges between sites to weave the complete graph.

### Functions:
- **`main()`**: The central function that acts as the application's driving force.
  
- **`getArrSiteInfo()`**: An auxiliary function adept at parsing string inputs to extract names of sites and distances, aiding the main algorithm.

### How to Use:
1. **Compile** the program: g++ -o mapper main.cpp
2. **Run** the application:
3. **Provide Input**: Enter the input as prompted, concluding the input sequence with 'End'.
