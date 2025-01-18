# Ta có đồ thị:
				
![image](https://github.com/user-attachments/assets/9803cd6e-68f5-48aa-b3ba-24e55743a2cf)


# Danh sách các cạnh và trọng số:

|Cạnh|Trọng Số|
| :-: | :-: |
|0-1|10|
|0-2|6|
|0-3|5|
|1-3|15|
|2-3|4|
#

# Kiểm nghiệm thuật toán:
|**Iteration**|**Unmarked Edge**|**Current Edge**|**Vertex1**|**Vertex2**|**Status**|
| :- | :-: | :-: | :- | :- | :- |
|1|<p>(2,3,4),(0,3,5),</p><p>(0,2,6),(0,1,10),</p><p>(1,3,15)</p>|(2,3,4)|2|3|Chọn|
|2|<p>(0,3,5),(0,2,6),</p><p>(0,1,10),(1,3,15)</p>|(0,3,5)|0|3|Chọn|
|3|<p>(0,2,6),(0,1,10),</p><p>(1,3,15)</p>|(0,2,6)|0|2|Bỏ qua|
|4|(0,1,10),(0,1,10)|(0,1,10)|0|1|Chọn|
|5|(1,3,15)|(1,3,15)|1|3|Dừng<br>(Đủ cạnh)|
# Các bước thực hiện:
Bước 1: Khởi tạo 

`	`Mỗi đỉnh coi là một tập hợp riêng biệt.

`	`Danh sách các cạnh được thu thập từ dồ thị.

|Cạnh|Trọng Số|
| :-: | :-: |
|0-1|10|
|0-2|6|
|0-3|5|
|1-3|15|
|2-3|4|

Bước 2: Sắp xếp các cạnh theo trọng số tăng dần

`	`Cạnh có trọng số nhỏ nhất trước.

|Cạnh|Trọng Số|
| :-: | :-: |
|2-3|4|
|0-3|5|
|0-2|6|
|0-1|10|
|1-3|15|

Bước 3: Duyệt qua từng cạnh và áp dụng Union-Find Duyệt qua các cạnh đã sắp xếp và thực hiện các thao tác sau: 

⮞ Iteration 1: Xét cạnh: (2,3,4) Kiểm tra: 2 và 3 khác tập → Chọn cạnh này. Tập hợp sau khi hợp nhất: {2,3}, {0}, {1} 

⮞ Iteration 2: Xét cạnh: (0,3,5) Kiểm tra: 0 và 3 khác tập → Chọn cạnh này. Tập hợp sau khi hợp nhất: {0,2,3}, {1} 

⮞ Iteration 3: Xét cạnh: (0,2,6) Kiểm tra: 0 và 2 cùng tập → Bỏ qua cạnh này (tránh tạo chu trình). 

⮞ Iteration 4: Xét cạnh: (0,1,10) Kiểm tra: 0 và 1 khác tập → Chọn cạnh này. Tập hợp sau khi hợp nhất: {0,1,2,3} 

⮞ Iteration 5: Xét cạnh: (1,3,15) Kiểm tra: 1 và 3 cùng tập → Bỏ qua cạnh này. 

Bước 4: Dừng lại khi đủ (n - 1) cạnh Với 4 đỉnh, chỉ cần 3 cạnh để tạo thành Cây khung nhỏ nhất. Các cạnh đã chọn: (2,3,4), (0,3,5), (0,1,10) 

Kết quả Cây khung nhỏ nhất (MST): (2,3,4), (0,3,5), (0,1,10) 


**Ouput:**

![image](https://github.com/user-attachments/assets/43f09e62-1d8f-40c6-affd-f502b5222b3d)

![image](https://github.com/user-attachments/assets/84978b5f-c894-422b-8c46-e48e8fb8c3b6)

