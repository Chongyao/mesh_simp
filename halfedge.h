#ifndef HALFEDGE_H
#define HALFEDGE_H
#include<memory>
#include<vector>
#include<string>
#include"zjucad/matrix/include/matrix.h"

struct H_vertex ;
struct H_face ;
struct H_edge;
struct H_vertex{
  H_vertex():
      is_exist(true){}
  //   double x;
  //   double y;
  //   double z;
  zjucad::matrix::matrix<double> position;
  size_t edge_;
  bool is_exist;
  zjucad::matrix::matrix<double> Kp;
};
struct H_face{
  H_face():
      is_exist(true){}
  size_t edge_;
  bool is_exist;
  zjucad::matrix::matrix<double> Kp;
};
struct H_edge{ // read_only to others
  H_edge():
      oppo_(-1),  is_exist(true) {}

  size_t next_, prev_, face_, vertex_;
  int oppo_;
  //  const halfedge &HE_;
  double length;
  bool is_exist;
};
// struct vertex_pair{
//   size_t p , q ;
// };

typedef std::pair<size_t, size_t> vertex_pair;

class halfedge
{
 public:
  halfedge();

  std::vector<int> init_faces;
  int read_data(const std::string &input_file);

  void construct_half_edges();

  //core structure
  std::vector<H_edge> half_edges_;
  std::vector<H_face> faces_;
  std::vector<H_vertex> vertexs_;

  //get information

  void halfedge_to_obj( const std::string & outfile);


  void cal_Kp_face(H_face & face_);
  void cal_Kp_vertex(H_vertex &vertex_);
  void cal_Kp_vertexs_();

  int correct_vertex(const size_t &vertex_id);
 private:
  void read_vertex(std::ifstream &fin, std::string &keyword);
  void read_face(std::ifstream &fin, std::string &keyword);
  void read_anno(std::ifstream &fin, std::string &keyword);


  std::string filename;
};
#endif // HALFEDGE_H
