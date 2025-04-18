# Diffie-Hellman
Program C about Diffie-Hellman


Example:
Trao đổi khóa Diffie-Hellman qua UDP (C++)
Chương trình C++ sử dụng giao thức UDP cho phép hai bên thiết lập một kênh giao tiếp an toàn. Để đơn giản, ta gọi chương trình phía Host là do Alice thực thi, còn chương trình phía Client là do Bob thực thi.

Alice và Bob chia sẻ trước một mật khẩu chung PW, bao gồm 6 ký tự số, cùng với các tham số (p, g) cho thuật toán trao đổi khóa Diffie-Hellman. Mục tiêu của họ là thiết lập một kênh liên lạc bảo mật cung cấp:

Tính bảo mật dữ liệu (confidentiality)

Tính toàn vẹn dữ liệu (integrity)

Quá trình này bao gồm 2 bước:

Bước 1: Thiết lập khóa phiên (session key)
Quá trình trao đổi khóa được thực hiện theo giao thức sau:

Alice → Bob: Gửi Epw (g^x mod p)
(gửi giá trị (g^x mod p) được mã hóa bằng mật khẩu chung PW)

Bob → Alice: Gửi Epw (g^y mod p)
(gửi giá trị (g^y mod p) được mã hóa bằng mật khẩu chung PW)

Sau khi nhận được thông tin từ phía bên kia, Alice và Bob tính toán khóa phiên chung như sau:
K = H (g^xy mod p)
Trong đó H là một hàm băm mật mã (hash function).

Thuật toán mã hóa được sử dụng: RC4

Hàm băm: SHA-1

Bước 2: Giao tiếp bảo mật bằng khóa phiên
Sau khi khóa phiên K được thiết lập, mỗi khi Alice gửi một thông điệp M cho Bob, cô ấy thực hiện:

Tính H = Hash(K || M)
(|| là phép nối chuỗi)

Tính C = Ek(M || H)
(mã hóa chuỗi thông điệp M nối với giá trị hash bằng khóa phiên K)

Gửi C cho Bob

Khi Bob nhận được bản mã C, anh ấy:

Giải mã C để thu được M || H
M || H = Dk(C)

Tính H' = Hash(K || M)

So sánh H' với H. Nếu bằng nhau, Bob chấp nhận thông điệp M; nếu không, từ chối thông điệp vì không đảm bảo toàn vẹn.

Quy trình tương tự cũng được áp dụng khi Bob gửi thông điệp cho Alice.
