# TF2_TB3
Script para navegación con FM Square en el Turtlebot3 (simulado)
La toolbox original de FM2 viene de: https://es.mathworks.com/matlabcentral/fileexchange/6110-toolbox-fast-marching

Pasos para lanzar el navegador:

EN TERMINAL, LANZAR:
- Terminal 1: roslaunch turtlebot3_gazebo turtlebot3_world.launch
- Terminal 2: roslaunch turtlebot3_navigation turtlebot3_navigation.launch
- Terminal 3 (OPCIONAL): roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch 

EN MATLAB: 
- Ejecutar el script Turtlebot3_FMSquare.m

El mapa que utiliza es el de haber mapeado el mundo que se abre por defecto con el TB3. Si se modifica y se añaden nuevos obstáculos, el robot debería detectarlos con el láser y replanificar en tiempo real.
