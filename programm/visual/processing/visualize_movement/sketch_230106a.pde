import controlP5.*;
ControlP5 cp5;


int h = 1000;
int w = 1000;

PGraphics sliders_view_port;
PGraphics mainwindow_view_port;

sliders_panel[] sliders;
sliders_panel[] sliders2;

int[] size_for_box = {100,30,10};


final float sphere_radius = 10;
final int count_nodes = 20;
final int count_range = 3;

float[][] absolute_sphere_coordinate;

final int[][] coordinate_hand = {
    {0,0,0},
    {2,1,0},
    {1,2,0},
    {0,2,0},
    {-1,2,0},
    {-2,2,0},
    {1,4,0},
    {0,4,0},
    {-1,4,0},
    {-2,4,0},
    
    {8,0,0},
    {6,1,0},
    {7,2,0},
    {8,2,0},
    {9,2,0},
    {10,2,0},
    {7,4,0},
    {8,4,0},
    {9,4,0},
    {10,4,0}
};

final color[] color_sphere = {
  #b55909,
  #0e012d,
  #3f164c,
  #3c3aa8,
  #229131,
  #9ab9ed,
  #ced1e8,
  #28160d,
  #313a2f,
  #27363a,
  #04300c,
  #76797c,
  #1d1b1e,
  #146047,
  #e8a2b3,
  #4f0e3b,
  #17269b,
  #a82f7d,
  #3cacb2,
  #e5ceac,
  #6b214b,
  #dbb4a4,
  #0c070c,
  #ce0659,
  #937d23,
  #b5b7b7,
  #4b51cc,
  #cbdd44,
  #ede1e3,
  #8d70b2,
  #060703,
  #1b9b07,
  #3f7229,
  #0d6684,
  #50e5de,
  #758c83,
  #84a87a,
  #59300f,
  #96c7f2,
  #70ff63,
};

final int[][] vertex_arr = {
   {0, 1},
   {0, 2},
   {0, 3},
   {0, 4},
   {0, 5},
   {2, 6},
   {3, 7},
   {4, 8},
   {5, 9},
   {10, 11},
   {10, 12},
   {10, 13},
   {10, 14},
   {10, 15},
   {12, 16},
   {13, 17},
   {14, 18},
   {15, 19}
};

boolean key_press = false;

float rx = degrees(radians(0)),
      ry = degrees(radians(0)),
      rz = degrees(radians(0)),
      mvx = 0,
      mvy = 0,
      mvz = 0,
      scl = 1;

int selector = 0; //0 = all

void setup()  {
  
  cp5 = new ControlP5(this);
  size(1000, 1000, P3D);
  sliders_view_port = createGraphics(100, 1000);
  mainwindow_view_port = createGraphics(1000 - 100, 1000, P3D);
  noStroke();
  fill(204);
  
  sliders = new sliders_panel[count_nodes];
  //height for every sliders panel 
  float h = height / (count_nodes + 2); //2 it's top and bottom margin
  for (int i = 0; i < count_nodes; i++) {
    //min start pos 100
     sliders[i] = new sliders_panel(int(h), 100, 0, int(h + h/count_nodes) * (i + 1), str(i) + "m", cp5);
  }
  
  sliders2 = new sliders_panel[count_nodes];
  //height for every sliders panel 
  for (int i = 0; i < count_nodes; i++) {
    //min start pos 100
     sliders2[i] = new sliders_panel(int(h), 100, 150, int(h + h/count_nodes) * (i + 1), str(i) + "r", cp5);
  }
  
  
  mvx = width /2;
  mvy = height /2;
  
  absolute_sphere_coordinate = new float[count_nodes][3];
  for(int i = 0; i < count_nodes; i++)
  {
    for (int j = 0; j < 3; j++) 
    {
      absolute_sphere_coordinate[i][j] = coordinate_hand[i][j] * sphere_radius * 4;
    }

  }
    
  
}

void draw()  {
  
  background(0);
  sliders_view_port.beginDraw();
  for (int i = 0; i < count_nodes; i++) {
     sliders[i].draw();
  }
  
  sliders_view_port.endDraw();
  
  
  pushMatrix();

  scale(scl);
  
  noStroke();
  lights();
  
  translate(mvx, mvy, rz);
  rotateX(degrees(radians(rx)));
  rotateY(degrees(radians(ry)));
  rotateZ(degrees(radians(rz)));
  //box(size_for_box[0],size_for_box[1],size_for_box[2]);
  
  for(int i = 0; i < count_nodes; i++) {
      float x, y, z;
      x = absolute_sphere_coordinate[i][0];
      y = absolute_sphere_coordinate[i][1];
      z = absolute_sphere_coordinate[i][2];

      
     pushMatrix();
     
     
      rotateX(sliders2[i].getvalue(0));
      rotateY(sliders2[i].getvalue(1));
      rotateZ(sliders2[i].getvalue(2));
     
     translate(x, y, z);
     
     fill(0, 408, 612);
     textSize(sphere_radius * 2);
     text(i, 0, 0, sphere_radius + 1);
     
     noStroke();
     lights();
     
     fill(color_sphere[i]);
     sphere(sphere_radius);
     popMatrix();
  }
  
  for (int i = 0; i < vertex_arr.length; i++)   {
     int start = vertex_arr[i][0];
     int end = vertex_arr[i][1];
     stroke(126);
     line(absolute_sphere_coordinate[start][0], absolute_sphere_coordinate[start][1], absolute_sphere_coordinate[start][2],
             absolute_sphere_coordinate[end][0], absolute_sphere_coordinate[end][1], absolute_sphere_coordinate[end][2]);

    
  };
  
  
  

  
  
  if(key_press) {
    switch(key){
    case '0' :
        selector = 0;
        break;
        
    case '1':
        selector = 1;
        break;
    
    case 'a':
        if (selector == 0) {
            mvx += scl;
        }
        else {
           rx += 0.01; 
        }
        break;
        
    case 'd':
        if (selector == 0) {
            mvx--;
        }
        else {
           rx -= 0.01; 
        }
        break;
    
    case 'w':
        if (selector == 0) {
            mvy++;
        }
        else {
           ry += 0.01; 
        }
        break;
        
    case 's':
        if (selector == 0) {
            mvy--;
        }
        else {
           ry -= 0.01; 
        }
        break;
        
    case 'q':
        if (selector == 0) {
            mvz++;
        }
        else {
           rz += 0.01; 
        }
        break;
        
    case 'e':
        if (selector == 0) {
            mvz--;
        }
        else {
           rz -= 0.01; 
        }
        break;
    
    case 'r':
      scl  += 0.01;
      break;
    
    case 'f':
      scl  -= 0.01;
        break;
    }

  }
  
    popMatrix();
  
  for(int i = 0; i < count_nodes; i++)
  {
    for (int j = 0; j < 3; j++) 
    {
      absolute_sphere_coordinate[i][j] = coordinate_hand[i][j] * sphere_radius * 4 + sliders[i].getvalue(j);
    }

  }
  
}


void keyPressed() {
  key_press = true;
}

void keyReleased() {
   key_press = false; 
}

public class sliders_panel {
  int h = 0;
  int w = 0;
  int left_top_angle_x = 0;
  int left_top_angle_y = 0;
  String text = "";
  
  
  int x, y, z;
  Slider S1;
  Slider S2;
  Slider S3;
  
  sliders_panel(int h, int w, int left_top_angle_x, int left_top_angle_y, String text, ControlP5 cp5){
    this.h = h;
    this.w = w;
    this.left_top_angle_x = left_top_angle_x;
    this.left_top_angle_y = left_top_angle_y;
    this.text = text;
    
    
    
    S1 = cp5.addSlider(this.text + "x", 0, 100,
                  0, this.left_top_angle_x, this.left_top_angle_y + ((this.h / 3) * 0), 
                  int(this.w - (this.w * 0.01)) , int(this.h * 0.30));
              
    S2 = cp5.addSlider(this.text + "y", 0, 100,
                    0, this.left_top_angle_x, this.left_top_angle_y + ((this.h / 3) * 1), 
                    int(this.w - (this.w * 0.01)) , int(this.h * 0.30));
  
    S3 = cp5.addSlider(this.text + "z",  0, 100,
                    0, this.left_top_angle_x, this.left_top_angle_y + ((this.h / 3) * 2), 
                    int(this.w - (this.w * 0.01)) , int(this.h * 0.30));
  
                  
  }
  
  void draw() {
    
  }
  
  float getvalue(int index){
      if (index == 0)
      {
        return S1.getValue();
      };
      if (index == 1)
      {
        return S2.getValue();
      };
      if (index == 2)
      {
        return S3.getValue();
      };
      return 0;
  }
  
  
  
  
}
