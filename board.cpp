#include "tile.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include "board.hpp"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

board::board(){
    tiles = initialBoard();
}

vector<tile>& board::get_board(){
    return tiles;
}

void board::printBoard(){
    for (int i = 0; i < 19; i++){
        tiles[i].printTile();
    }
}

vector<tile> board::initialBoard(){
    
    // ************************ ALL VERTICES ************************
    vertex v0(0); vertex v1(1); vertex v2(2); vertex v3(3); vertex v4(4); vertex v5(5);
    vertex v6(6); vertex v7(7); vertex v8(8); vertex v9(9); vertex v10(10); vertex v11(11);
    vertex v12(12); vertex v13(13); vertex v14(14); vertex v15(15); vertex v16(16); vertex v17(17);
    vertex v18(18); vertex v19(19); vertex v20(20); vertex v21(21); vertex v22(22); vertex v23(23);
    vertex v24(24); vertex v25(25); vertex v26(26); vertex v27(27); vertex v28(28); vertex v29(29);
    vertex v30(30); vertex v31(31); vertex v32(32); vertex v33(33); vertex v34(34); vertex v35(35);
    vertex v36(36); vertex v37(37); vertex v38(38); vertex v39(39); vertex v40(40); vertex v41(41);
    vertex v42(42); vertex v43(43); vertex v44(44); vertex v45(45); vertex v46(46); vertex v47(47);
    vertex v48(48); vertex v49(49); vertex v50(50); vertex v51(51); vertex v52(52); vertex v53(53);
    // ************************ ALL EDGES ************************
    edge e0(&v0, &v1); edge e1(&v1, &v2); edge e2(&v2, &v31); edge e3(&v31, &v30); edge e4(&v30, &v29); edge e5(&v29, &v0); // tile 10
    edge e6(&v2, &v3); edge e7(&v3, &v4); edge e8(&v4, &v33); edge e9(&v33, &v32); edge e10(&v32, &v31); // tile 2
    edge e11(&v4, &v5); edge e12(&v5, &v6); edge e13(&v6, &v7); edge e14(&v7, &v34); edge e15(&v34, &v33); // tile 9
    
    edge e16(&v28, &v29); edge e17(&v30, &v47); edge e18(&v47, &v46); edge e19(&v46, &v27); edge e20(&v27, &v28); // tile 12
    edge e21(&v32, &v49); edge e22(&v49, &v48); edge e23(&v48, &v47); // tile 6
    edge e24(&v34, &v35); edge e25(&v35, &v50); edge e26(&v50, &v49); // tile 4
    edge e27(&v7, &v8); edge e28(&v8, &v9); edge e29(&v9, &v36); edge e30(&v36, &v35); // tile 10
    
    edge e31(&v26, &v27); edge e32(&v46, &v45); edge e33(&v45, &v24); edge e34(&v24, &v25); edge e35(&v25, &v26); // tile 9
    edge e36(&v48, &v53); edge e37(&v53, &v44); edge e38(&v44, &v45); // tile 11
    edge e39(&v50, &v51); edge e40(&v51, &v52); edge e41(&v52, &v53); // desert
    edge e42(&v36, &v37); edge e43(&v37, &v38); edge e44(&v38, &v51); // tile 3
    edge e45(&v9, &v10); edge e46(&v10, &v11); edge e47(&v11, &v12); edge e48(&v12, &v37);// tile 8

    edge e49(&v44, &v43); edge e50(&v43, &v22); edge e51(&v22, &v23); edge e52(&v23, &v24); // tile 8
    edge e53(&v52, &v41); edge e54(&v41, &v42); edge e55(&v42, &v43); // tile 3
    edge e56(&v38, &v39); edge e57(&v39, &v40); edge e58(&v40, &v41); // tile 4
    edge e59(&v12, &v13); edge e60(&v13, &v14); edge e61(&v14, &v39); // tile 5
    
    edge e62(&v42, &v19); edge e63(&v19, &v20); edge e64(&v20, &v21); edge e65(&v21, &v22); // tile 5
    edge e66(&v40, &v17); edge e67(&v17, &v18); edge e68(&v18, &v19); // tile 6
    edge e69(&v14, &v15); edge e70(&v15, &v16); edge e71(&v16, &v17); // tile 11
    // ************************ ALL TILES ************************
    // vector<vertex> vertexes1 = {v0, v1, v2, v31, v30, v29};
    // vector<edge> edges1 = {e0, e1, e2, e3, e4, e5};
    // tile tile1("iron", 10, vertexes1, edges1); // 10

    vector<vertex*> vertexes1 = {&v0, &v1, &v2, &v31, &v30, &v29};
    vector<edge*> edges1 = {&e0, &e1, &e2, &e3, &e4, &e5};
    tile tile1("iron", 10, vertexes1, edges1); // 10

    // vector<vertex> vertexes2 = {v2, v3, v4, v33, v32, v31};
    // vector<edge> edges2 = {e2 ,e6, e7, e8, e9, e10};
    // tile tile2("sheep", 2, vertexes2, edges2); // 2

    vector<vertex*> vertexes2 = {&v2, &v3, &v4, &v33, &v32, &v31};
    vector<edge*> edges2 = {&e2 ,&e6, &e7, &e8, &e9, &e10};
    tile tile2("sheep", 2, vertexes2, edges2); // 2

    // vector<vertex> vertexes3 = {v4, v5, v6, v7, v34, v33};
    // vector<edge> edges3 = {e8, e11, e12, e13, e14, e15};
    // tile tile3("wood", 9, vertexes3, edges3); // 9

    vector<vertex*> vertexes3 = {&v4, &v5, &v6, &v7, &v34, &v33};
    vector<edge*> edges3 = {&e8, &e11, &e12, &e13, &e14, &e15};
    tile tile3("wood", 9, vertexes3, edges3); // 9

    // vector<vertex> vertexes4 = {v28, v29, v30, v47, v46, v27};
    // vector<edge> edges4 = {e4 ,e16, e17, e18, e19, e20};
    // tile tile4("wheat", 12, vertexes4, edges4); // 12

    vector<vertex*> vertexes4 = {&v28, &v29, &v30, &v47, &v46, &v27};
    vector<edge*> edges4 = {&e4 ,&e16, &e17, &e18, &e19, &e20};
    tile tile4("wheat", 12, vertexes4, edges4); // 12

    // vector<vertex> vertexes5 = {v32, v31, v30, v49, v48, v47};
    // vector<edge> edges5 = {e3 ,e10, e17, e21, e22, e23};
    // tile tile5("clay", 6, vertexes5, edges5); // 6

    vector<vertex*> vertexes5 = {&v32, &v31, &v30, &v49, &v48, &v47};
    vector<edge*> edges5 = {&e3 ,&e10, &e17, &e21, &e22, &e23};
    tile tile5("clay", 6, vertexes5, edges5); // 6

    // vector<vertex> vertexes6 = {v32, v33, v34, v35, v50, v49};
    // vector<edge> edges6 = {e9 ,e15, e24, e25, e26, e21};
    // tile tile6("sheep", 4, vertexes6, edges6); // 4

    vector<vertex*> vertexes6 = {&v32, &v33, &v34, &v35, &v50, &v49};
    vector<edge*> edges6 = {&e9 ,&e15, &e24, &e25, &e26, &e21};
    tile tile6("sheep", 4, vertexes6, edges6); // 4

    // vector<vertex> vertexes7 = {v34, v7, v8, v9, v36, v35};
    // vector<edge> edges7 = {e14 ,e27, e28, e29, e30, e24};
    // tile tile7("clay", 10, vertexes7, edges7); // 10

    vector<vertex*> vertexes7 = {&v34, &v7, &v8, &v9, &v36, &v35};
    vector<edge*> edges7 = {&e14 ,&e27, &e28, &e29, &e30, &e24};
    tile tile7("clay", 10, vertexes7, edges7); // 10

    // vector<vertex> vertexes8 = {v26, v27, v46, v45, v24, v25};
    // vector<edge> edges8 = {e31 ,e19 , e32, e33, e34, e35};
    // tile tile8("wheat", 9, vertexes8, edges8); // 9

    vector<vertex*> vertexes8 = {&v26, &v27, &v46, &v45, &v24, &v25};
    vector<edge*> edges8 = {&e31 ,&e19 , &e32, &e33, &e34, &e35};
    tile tile8("wheat", 9, vertexes8, edges8); // 9

    // vector<vertex> vertexes9 = {v48, v47, v46, v53, v44, v45};
    // vector<edge> edges9 = {e23 ,e18, e36, e37, e38, e32};
    // tile tile9("wood", 11, vertexes9, edges9); // 11

    vector<vertex*> vertexes9 = {&v48, &v47, &v46, &v53, &v44, &v45};
    vector<edge*> edges9 = {&e23 ,&e18, &e36, &e37, &e38, &e32};
    tile tile9("wood", 11, vertexes9, edges9); // 11

    // vector<vertex> vertexes10 = {v50, v49, v48, v53, v52, v51};
    // vector<edge> edges10 = {e26 ,e22, e36, e40, e41, e39};
    // tile tile10("desert", 0, vertexes10, edges10); // desert

    vector<vertex*> vertexes10 = {&v50, &v49, &v48, &v53, &v52, &v51};
    vector<edge*> edges10 = {&e26 ,&e22, &e36, &e40, &e41, &e39};
    tile tile10("desert", 0, vertexes10, edges10); // desert

    // vector<vertex> vertexes11 = {v36, v35, v37, v38, v51, v50};
    // vector<edge> edges11 = {e39 ,e44, e43, e42, e30, e25};
    // tile tile11("wood", 3, vertexes11, edges11); // 3

    vector<vertex*> vertexes11 = {&v36, &v35, &v37, &v38, &v51, &v50};
    vector<edge*> edges11 = {&e39 ,&e44, &e43, &e42, &e30, &e25};
    tile tile11("wood", 3, vertexes11, edges11); // 3

    // vector<vertex> vertexes12 = {v9, v10, v11, v12, v37, v36};
    // vector<edge> edges12 = {e42 ,e48, e47, e46, e45, e29};
    // tile tile12("iron", 8, vertexes12, edges12); // 8

    vector<vertex*> vertexes12 = {&v9, &v10, &v11, &v12, &v37, &v36};
    vector<edge*> edges12 = {&e42 ,&e48, &e47, &e46, &e45, &e29};
    tile tile12("iron", 8, vertexes12, edges12); // 8

    // vector<vertex> vertexes13 = {v44, v43, v22, v23, v24, v45};
    // vector<edge> edges13 = {e52 ,e51, e50, e49, e38, e33};
    // tile tile13("wood", 8, vertexes13, edges13); // 8

    vector<vertex*> vertexes13 = {&v44, &v43, &v22, &v23, &v24, &v45};
    vector<edge*> edges13 = {&e52 ,&e51, &e50, &e49, &e38, &e33};
    tile tile13("wood", 8, vertexes13, edges13); // 8

    // vector<vertex> vertexes14 = {v52, v41, v42, v43, v44, v53};
    // vector<edge> edges14 = {e49 ,e55, e54, e53, e41, e37};
    // tile tile14("iron", 3, vertexes14, edges14); // 3

    vector<vertex*> vertexes14 = {&v52, &v41, &v42, &v43, &v44, &v53};
    vector<edge*> edges14 = {&e49 ,&e55, &e54, &e53, &e41, &e37};
    tile tile14("iron", 3, vertexes14, edges14); // 3

    // vector<vertex> vertexes15 = {v38, v39, v40, v41, v52, v51};
    // vector<edge> edges15 = {e53 ,e58, e57, e56, e44, e40};
    // tile tile15("wheat", 4, vertexes15, edges15); // 4

    vector<vertex*> vertexes15 = {&v38, &v39, &v40, &v41, &v52, &v51};
    vector<edge*> edges15 = {&e53 ,&e58, &e57, &e56, &e44, &e40};
    tile tile15("wheat", 4, vertexes15, edges15); // 4

    // vector<vertex> vertexes16 = {v12, v13, v14, v39, v38, v37};
    // vector<edge> edges16 = {e56 ,e61, e60, e59, e48, e43};
    // tile tile16("sheep", 5, vertexes16, edges16); // 5

    vector<vertex*> vertexes16 = {&v12, &v13, &v14, &v39, &v38, &v37};
    vector<edge*> edges16 = {&e56 ,&e61, &e60, &e59, &e48, &e43};
    tile tile16("sheep", 5, vertexes16, edges16); // 5

    // vector<vertex> vertexes17 = {v42, v19, v20, v21, v22, v43};
    // vector<edge> edges17 = {e65 ,e64, e63, e62, e55, e50};
    // tile tile17("clay", 5, vertexes17, edges17); // 5

    vector<vertex*> vertexes17 = {&v42, &v19, &v20, &v21, &v22, &v43};
    vector<edge*> edges17 = {&e65 ,&e64, &e63, &e62, &e55, &e50};
    tile tile17("clay", 5, vertexes17, edges17); // 5

    // vector<vertex> vertexes18 = {v40, v17, v18, v19, v42, v41};
    // vector<edge> edges18 = {e67 ,e66, e68, e62, e54, e58};
    // tile tile18("wheat", 6, vertexes18, edges18); // 6

    vector<vertex*> vertexes18 = {&v40, &v17, &v18, &v19, &v42, &v41};
    vector<edge*> edges18 = {&e67 ,&e66, &e68, &e62, &e54, &e58};
    tile tile18("wheat", 6, vertexes18, edges18); // 6

    // vector<vertex> vertexes19 = {v14, v15, v16, v17, v40, v39};
    // vector<edge> edges19 = {e66 ,e71, e70, e69, e61, e57};
    // tile tile19("sheep", 11, vertexes19, edges19); // 11

    vector<vertex*> vertexes19 = {&v14, &v15, &v16, &v17, &v40, &v39};
    vector<edge*> edges19 = {&e66 ,&e71, &e70, &e69, &e61, &e57};
    tile tile19("sheep", 11, vertexes19, edges19); // 11

    // ************************ ADDING TILES TO BOARD ************************
    vector<tile> tiles = {tile1, tile2, tile3, tile4, tile5, tile6, tile7, tile8, tile9, tile10, tile11, tile12, tile13, tile14, tile15, tile16, tile17, tile18, tile19};

    return tiles;
}
