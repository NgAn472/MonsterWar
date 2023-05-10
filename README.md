# Họ và tên: Nguyễn Bình An MSV: 20020747

# Giới thiệu

 MonsterWar là tựa game mô phỏng lại game online Pokiwar đã từng xuất hiện trên Zingme
Game hiện tại có 1 chế độ là PVE.

Mục tiêu của người chơi là "ăn" các khối kim cương để tạo ấn các hiệu ứng buff sức mạnh, lẫn tấn công cho character mình điều khiển để sống sót và tiêu diệu character của máy
Các khối kim cương được "ăn" bằng cách di chuyển vị trí các khối gần nhau để tạo nên hàng dọc hoặc hàng ngang có từ 3 ô giống nhau trở lên
Hiện Game mới có 1 character và có thể bổ sung dễ bằng cách thêm thông tin, animation

# Khi chạy game:

+Play để bắt đầu chơi ở level mặc định

+Setting để chỉnh level game cũng như chỉnh quái thú mình muốn chơi

+Quit để thoát game

# Gameplay:
Game nhận dữ liệu từ chuột để chọn được 2 ô người chơi muốn di chuyển 
<img width="746" alt="image" src="https://github.com/NgAn472/MonsterWar/assets/126228740/abc93cc0-d69a-4d88-a526-b637e961bbfb">

Ba thanh trạng thái của character tương ứng là các chỉ số hp, mp và pow:

+hp của char nào về 0 tức char đó thua
+mp giúp chuyển hóa thành hp
+pow có khả năng nâng cao chỉ số tấn công

## Các ô với các hiệu ứng tương ứng:

<img width="256" alt="1Skill" src="https://github.com/NgAn472/MonsterWar/assets/126228740/a8b6a429-6af7-4560-b344-f9f43f609bdc">

Giúp char phát động tấn công



<img width="256" alt="2Skill" src="https://github.com/NgAn472/MonsterWar/assets/126228740/638769b1-94bf-4f0e-9ae5-66d32135f444">

Hồi phục hp



<img width="256" alt="3Skill" src="https://github.com/NgAn472/MonsterWar/assets/126228740/3d936a46-f667-45de-b0fe-c13053403000">

Tăng mana



<img width="256" alt="4Skill" src="https://github.com/NgAn472/MonsterWar/assets/126228740/6ed2eac4-74ac-4471-976c-6072e1054c68">

Tăng pow



<img width="256" alt="5Skill" src="https://github.com/NgAn472/MonsterWar/assets/126228740/3df7977f-deca-4cc8-a3a3-3296eea0bde8">

Tạo khiên giảm sát thương trong lần bị tấn công tiếp theo



<img width="256" alt="6Skill" src="https://github.com/NgAn472/MonsterWar/assets/126228740/9a0e4152-291a-4347-b2d6-3176b4c8e818">

Tăng agl (khả năng né đòn) trong turn tiếp theo(kể cả khi không bị tấn công, chỉ số agl cũng sẽ giảm về mức cơ bản)



<img width="256" alt="7Skill" src="https://github.com/NgAn472/MonsterWar/assets/126228740/dbac3258-73eb-42e8-b3fb-04d7e0d9f700">

Chuyển hóa mana thành máu

Sau khi di chuyển thành công, sẽ hiện thị toàn bộ các hiệu ứng mà mỗi bên đã ăn được
<img width="773" alt="image" src="https://github.com/NgAn472/MonsterWar/assets/126228740/b6721e5c-fffa-4cb6-bd44-4ad3e7be8ec8">



## lưu ý:
nếu người chơi không chọn vị trí để di chuyển ô trong 20s hoặc khi đổi chỗ 2 ô lại không tạo thành được hàng ngang hoặc dọc có 3 ô trở lên giống nhau thì sẽ bị mất lượt đó

Trong trường hợp người chơi không tìm được vị trí khả thi để di chuyển có thể ấn vào dấu tick

<img width="50" alt="check-mark" src="https://github.com/NgAn472/MonsterWar/assets/126228740/85f06e05-690c-4d04-bfbe-eb9ee589d92a">

Nếu dấu tích chuyển xanh đồng nghĩa với việc có vị trí khả thi

Còn nếu không có vị trí khả thi thì game sẽ tạo 1 bảng mới để người chơi tiếp tục chơi

