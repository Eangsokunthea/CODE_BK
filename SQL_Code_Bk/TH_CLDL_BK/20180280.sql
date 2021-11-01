
-----Buổi TH3-------

/*3A.1-Cho biết NGAYTD, TENCLB1, TENCLB2, KETQUA các trận đấu diễn ra vào tháng 3 trên sân
	nhà mà không bị thủng lưới.
*/

SELECT td.NGAYTD, clb1.TENCLB, clb2.TENCLB, td.KETQUA
FROM TRANDAU td, CAULACBO clb1, CAULACBO clb2
WHERE td.MACLB1 = clb1.MACLB 
AND td.MACLB2 = clb2.MACLB 
AND DATEPART(MONTH,td.NGAYTD) = 3
AND (td.MASAN = clb1.MASAN 
AND CAST(RIGHT(td.KETQUA, LEN(td.KETQUA) - CHARINDEX('-', td.KETQUA) ) AS int) = 0
OR td.MASAN = clb2.MASAN 
AND CAST(LEFT(td.KETQUA, LEN(td.KETQUA) - CHARINDEX('-', td.KETQUA)- 1) AS int) = 0)

/*3A.2-Cho biết mã số, họ tên, ngày sinh của những cầu thủ có họ lót là “Công”*/

SELECT MACT, HOTEN,NGAYSINH
FROM CAUTHU
WHERE HOTEN like N'%Công%'

/*3A.3-Cho biết mã số, họ tên, ngày sinh của những cầu thủ có họ không phải là họ “Nguyễn “*/

SELECT MACT, HOTEN,NGAYSINH
FROM CAUTHU
WHERE HOTEN not like N'Nguyễn%'

/*3A.4. Cho biết mã huấn luyện viên, họ tên, ngày sinh, địa chỉ của những huấn luyện viên Việt
Nam có tuổi nằm trong khoảng 35-40*/

SELECT MAHLV, TENHLV, NGAYSINH, DIACHI
FROM HUANLUYENVIEN
WHERE MAQG = (SELECT MAQG FROM QUOCGIA WHERE TENQG = N'Việt Nam')
AND (YEAR(GETDATE()) - YEAR(NGAYSINH)) >= 35 OR
(YEAR(GETDATE()) - YEAR(NGAYSINH)) <= 40

/*3A.5. Cho biết tên câu lạc bộ có huấn luyện viên trưởng sinh vào ngày 20 tháng 5*/

SELECT TENCLB 
FROM CAULACBO AS CLB, HLV_CLB AS HLV_CLB,HUANLUYENVIEN AS HLV
WHERE CLB.MACLB = HLV_CLB.MACLB 
AND HLV_CLB.MAHLV = HLV.MAHLV
AND MONTH (NGAYSINH) = 5
AND DAY(NGAYSINH) = 20

/*3A.6. Cho biết tên câu lạc bộ, tên tỉnh mà CLB đang đóng có số bàn thắng nhiều nhất tính đến
hết vòng 3 năm 2009*/

SELECT TENCLB, TENTINH
FROM CAULACBO, TINH AS TINH ,BANGXH AS BANGXH
WHERE TINH.MATINH= TINH.MATINH
AND BANGXH.MACLB = BANGXH.MACLB
AND VONG = 3
AND SUBSTRING(HIEUSO,1,1) = (SELECT MAX(SUBSTRING(HIEUSO,1,1))
FROM BANGXH
WHERE VONG = 3)

/*3B.1. Cho biết mã câu lạc bộ, tên câu lạc bộ, tên sân vận động, địa chỉ và số lượng cầu thủ nước
ngoài (Có quốc tịch khác “Việt Nam”) tương ứng của các câu lạc bộ có nhiều hơn 2 cầu
thủ nước ngoài.
*/

SELECT CLB.MACLB,TENCLB,TENSAN,SANVD.DIACHI,COUNT(MACT)
AS SOCTNCOCNGOAL
FROM CAULACBO AS CLB, CAUTHU AS CAUTHU, SANVD AS SANVD
WHERE CLB.MACLB = CAUTHU.MACLB
AND CLB.MASAN = SANVD.MASAN 
AND CAUTHU.MAQG <> N'VN'
GROUP BY CLB.MACLB, TENSAN,SANVD.DIACHI HAVING COUNT(MACT) > 2

/*3B.2. Cho biết tên câu lạc bộ, tên tỉnh mà CLB đang đóng có hiệu số bàn thắng bại cao nhất
năm 2009.
*/

SELECT clb.TENCLB, tinh.TENTINH
FROM CAULACBO clb, TINH tinh, BANGXH bxh
WHERE clb.MATINH = tinh.MATINH AND bxh.MACLB = clb.MACLB
   AND bxh.VONG = 4
   AND (CAST(LEFT(bxh.HIEUSO, 1) AS int) - 
   CAST(RIGHT(bxh.HIEUSO, 1) AS int)) >= 
   ALL ( SELECT (CAST(LEFT(bxh1.HIEUSO, 1) AS int) - 
   CAST(RIGHT(bxh1.HIEUSO, 1) AS int))
   FROM BANGXH bxh1 
   WHERE bxh1.VONG = 4 )

/*3B.3. Cho biết danh sách các trận đấu ( NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA) của
câu lạc bộ CLB có thứ hạng thấp nhất trong bảng xếp hạng vòng 3 năm 2009.
-->	OK*/

SELECT NGAYTD,CLB1.TENCLB AS TENCLB1,CLB2.TENCLB AS TENCLB2, KETQUA
FROM TRANDAU AS TRANDAU, CAULACBO AS CLB1, CAULACBO AS CLB2
WHERE MACLB1 = CLB1.MACLB 
AND MACLB2 = CLB2.MACLB
AND TRANDAU.MASAN = TRANDAU.MASAN
AND (CLB1.MACLB = (SELECT TOP(1)  MACLB 
FROM BANGXH 
WHERE VONG = 3 order by HANG DESC)
OR CLB2.MACLB = (SELECT TOP(1) MACLB FROM BANGXH
WHERE  VONG = 3 order BY HANG DESC))

/*3B.4. Cho biết mã câu lạc bộ, tên câu lạc bộ đã tham gia thi đấu với tất cả các câu lạc bộ còn lại
(kể cả sân nhà và sân khách) trong mùa giải năm 2009.*/

SELECT clb.MACLB, clb.TENCLB
FROM CAULACBO clb, 
(SELECT td1.MACLB1, COUNT (td1.MACLB1) as SoTran1
FROM  TRANDAU td1
GROUP BY td1.MACLB1) SanNha,
(SELECT td2.MACLB2, COUNT (td2.MACLB2) as SoTran2
FROM TRANDAU td2
GROUP BY td2.MACLB2) SanKhach
WHERE clb.MACLB = SanNha.MACLB1 AND clb.MACLB = SanKhach.MACLB2
AND SanNha.SoTran1 + SanKhach.SoTran2 = 4

/*3B.5. Cho biết mã câu lạc bộ, tên câu lạc bộ đã tham gia thi đấu với tất cả các câu lạc bộ còn lại
( chỉ tính sân nhà) tro ng mùa giải năm 2009.
*/

SELECT td.MACLB1, clb.TENCLB, 
COUNT(td.MACLB1) AS [Trận sân nhà]
FROM CAULACBO clb, TRANDAU td
WHERE clb.MACLB = td.MACLB1 
GROUP BY td.MACLB1, clb.TENCLB 
HAVING COUNT(td.MACLB1) = 4


/*3C.1. Khi thêm cầu thủ mới, kiểm tra vị trí trên sân của cầu thủ chỉ thuộc một trong các vị trí
sau: Thủ môn, tiền đạo, tiền vệ, trung vệ, hậu vệ.OK*/

ALTER TABLE CAUTHU ADD CONSTRAINT CHECKVITRI CHECK
(VITRI = N'Thủ môn' OR VITRI = N'tiền đạo' OR VITRI = N'tiền vệ'
OR VITRI = N'trung vệ' OR VITRI = N'hậu vệ')

/*3C.2. Khi phân công huấn luyện viên, kiểm tra vai trò của huấn luyện vi ên chỉ thuộc một trong
các vai trò sau: HLV chính, HLV phụ, HLV thể lực, HLV thủ môn.*/

ALTER TABLE HLV_CLB ADD CONSTRAINT check_vaitro CHECK 
(VAITRO = N'HLV Chính' OR VAITRO = N'HLV Phụ' 
OR VAITRO = N'HLV thể lực' OR VAITRO = N'HLV thủ môn')

/*3C.3. Khi thêm cầu thủ mới, kiểm tra cầu thủ đó có tuổi phải đủ 18 trở lên (chỉ tính năm sinh)
OK*/

ALTER TABLE CAUTHU ADD CONSTRAINT CHECKTUOI CHECK
((YEAR(GETDATE()) - YEAR(NGAYSINH)) >= 18)

/*3C.4. Kiểm tra kết quả trận đấu có dạng số_bàn_thắng- số_bàn_thua
*/

ALTER TABLE TRANDAU ADD CONSTRAINT 
check_ketqua CHECK(KETQUA LIKE '%-%')

/*3D.1. Cho biết mã số, họ tên, ngày sinh, 
địa chỉ và vị trí của các cầu thủ thuộc đội bón g “SHB
Đà Nẵng” có quốc tịch “Bra-xin”
*/

CREATE VIEW [D1] AS 
SELECT MACT, HOTEN, NGAYSINH, DIACHI, VITRI
FROM CAUTHU
WHERE MACLB = (SELECT MACLB FROM CAULACBO
WHERE TENCLB = N'SHB Đà Nẵng', AND CAUTHU.MAQG =
(SELECT MAQG FROM QUOCGIA 
WHERE TENQG = N'Bra-xin')
SELECT * FROM [D1]

/*3D.2. Cho biết kết quả (MATRAN, NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA) các trận
đấu vòng 3 của mùa bóng năm 2009.*/

CREATE VIEW [D2] AS
SELECT MATRAN, NGAYTD,CLB1.TENCLB
AS[CLB1], CLB2.TENCLB AS [CLB2], KETQUA
FROM TRANDAU, CAULACBO AS CLB1, CAULACBO AS CLB2, SANVD AS SANVD
WHERE TRANDAU.MASAN = SANVD.MASAN
AND TRANDAU.MACLB1 =  CLB1.MACLB
AND TRANDAU.MACLB2 = CLB2.MACLB
AND VONG = 3 
AND NAM = 2009
SELECT * FROM [D2]

/*3D.3. Cho biết mã huấn luyện viên, họ tên, ngày sinh, địa chỉ, vai trò và tên CLB đang làm việc
của các huấn luyện viên có quốc tịch “Việt Nam”*/

CREATE VIEW [D3] AS
SELECT hlv.MAHLV, hlv.TENHLV, hlv.NGAYSINH, hlv.DIACHI, hc.VAITRO, clb.TENCLB
FROM HUANLUYENVIEN hlv, HLV_CLB hc, CAULACBO clb
WHERE hlv.MAHLV = hc.MAHLV 
AND hc.MACLB = clb.MACLB 
AND hlv.MAQG = (SELECT MAQG FROM QUOCGIA WHERE TENQG = N'Việt Nam')
SELECT * FROM [D3]

/*3D.4. Cho biết mã câu lạc bộ, tên câu lạc bộ, tên sân vận động, địa chỉ và số lượng cầu thủ
nước ngoài (có quốc tịch khác “Việt Nam”) tương ứng của các câu lạc bộ nhiều hơn 2
cầu thủ nước ngoài*/

CREATE VIEW [D4] AS
SELECT CLB.MACLB, TENCLB, TENSAN, SVD.DIACHI, count(CT.MACT) AS SOCAUTHUNUOCNGOAI
FROM CAULACBO CLB, SANVD SVD, CAUTHU CT
WHERE CLB.MASAN = SVD.MASAN 
AND CLB.MACLB = CT.MACLB 
AND CT.MAQG NOT LIKE (SELECT MAQG FROM QUOCGIA WHERE TENQG = N'Việt Nam')
GROUP BY CLB.MACLB, TENCLB, TENSAN, SVD.DIACHI
HAVING COUNT(CT.MACLB) >= 2
SELECT * FROM [D4]

/*3D.5. Cho biết tên tỉnh, số lượng câu thủ đang thi đấu ở vị trí tiền đạo trong các câu lạc bộ
thuộc địa bàn tỉnh đó quản lý.*/

CREATE VIEW [D5] AS
SELECT TENTINH, COUNT(MACT) AS SO_CT
FROM TINH AS TINH, CAULACBO AS CLB, CAUTHU 
WHERE TINH.MATINH = CLB.MATINH
AND CLB.MACLB = CAUTHU.MACLB
AND VITRI = N'tiền đạo'
GROUP BY TENTINH 
SELECT * FROM [D5]

/*3D.6. Cho biết tên câu lạc bộ,tên tỉnh mà CLB đang đóng nằm ở vị trí cao nhất của bảng xếp
hạng của vòng 3 năm 2009*/

CREATE VIEW [D6] AS
SELECT TENCLB, TENTINH
FROM CAULACBO AS CLB, TINH AS TINH 
WHERE CLB.MATINH = TINH.MATINH
AND CLB.MACLB = (SELECT MACLB FROM BANGXH
WHERE VONG = 3 AND NAM = 2009
AND HANG = 1)
SELECT * FROM [D6]

/*3D.7. Cho biết tên huấn luyện viên đang nắm giữ một vị trí trong 1 c âu lạc bộ mà chưa có số
điện thoại*/

CREATE VIEW [D7] AS
SELECT HLV.TENHLV
FROM HUANLUYENVIEN AS HLV INNER JOIN HLV HLV1 
ON HLV.MAHLV =  HLV.MAHLV 
WHERE HLV.DIENTHOAI LIKE 'AND HLV.VATRO NOT LIKE'
SELECT * FROM [D7]

/*3D.8. Liệt kê các huấn luyện viên thuộc quốc gia Việt Nam chưa làm công tác huấn luyện tại bất
kỳ một câu lạc b ộ nào*/

CREATE VIEW [D8] AS
SELECT TENHLV 
FROM HUANLUYENVIEN AS HLV, HLV_CLB, QUOCGIA AS QUOCGIA
WHERE HLV.MAHLV = HLV_CLB.MAHLV
AND MACLB IS NULL AND QUOCGIA.MAQG = HLV.MAQG 
AND TENQG = N'Việt Nam'
SELECT * FROM [D8]

/*3D.9. Cho biết kết quả các trận đấu đã diễn ra (MACLB1, MACLB2, NAM, VONG,
SOBANTHANG,SOBANTHUA)*/

CREATE VIEW [D9] AS
SELECT MACLB1, MACLB2, NAM, VONG, KETQUA
FROM TRANDAU
SELECT * FROM [D9]

/*3D.10. Cho biết kết quả các trận đấu trên sân nhà (MACLB, NAM, VONG,
SOBANTHANG, SOBANTHUA)*/

CREATE VIEW [D10] AS
SELECT MACLB1 AS MACLB, NAM, VONG, 
LEFT(KETQUA, 1) AS SOBANTHANG, RIGHT(KETQUA, 1) AS SOBANTHUA
FROM TRANDAU
SELECT * FROM [D10]

/*3D.11. Cho biết kết quả các trận đấu trên sân khách (MACLB, NAM, VONG,
SOBANTHANG,SOBANTHUA)*/

CREATE VIEW [D11] AS
SELECT MACLB2 AS MACLB, NAM, VONG, 
LEFT(KETQUA, 1) AS SOBANTHANG, RIGHT(KETQUA, 1) AS SOBANTHUA
FROM TRANDAU
SELECT * FROM [D11]

/*3D.12. Cho biết danh sách các trận đấu (NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA)
của câu lạc bộ CLB đang xếp hạng cao nhất tính đến hết vòng 3 năm 2009
*/

CREATE VIEW [D12] AS
SELECT NGAYTD, SVD.TENSAN, CLB1.TENCLB, CLB2.TENCLB, KETQUA
FROM TRANDAU TD, SANVD SVD, CAULACBO CLB1, CAULACBO CLB2
WHERE TD.MASAN = SVD.MASAN 
AND TD.MACLB1 = CLB1.MACLB 
AND CLB2.MACLB = TD.MACLB2 
AND TD.VONG <= 3 
AND TD.NAM = 2009
AND ((TD.MACLB1 = (SELECT MACLB FROM BANGXH WHERE VONG = 3 
AND NAM = 2009 AND HANG = 1)) OR 
(TD.MACLB2 = (SELECT MACLB 
FROM BANGXH WHERE VONG = 3 AND NAM = 2009 AND HANG = 1)))
SELECT * FROM [D12]

/*3D.13. Cho biết danh sách các trận đấu (NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA)
của câu lạc bộ CLB có thứ hạng thấp nhất trong bảng xếp hạng vòng 3 năm 2009*/

CREATE VIEW [D13] AS
SELECT NGAYTD, SVD.TENSAN, CLB1.TENCLB, CLB2.TENCLB, KETQUA
FROM TRANDAU TD, SANVD SVD, CAULACBO CLB1, CAULACBO CLB2
WHERE TD.MASAN = SVD.MASAN 
AND TD.MACLB1 = CLB1.MACLB 
AND CLB2.MACLB = TD.MACLB2 
AND TD.VONG <= 3 AND TD.NAM = 2009
AND ((TD.MACLB1 = (SELECT MACLB 
FROM BANGXH WHERE VONG = 3 AND NAM = 2009 
AND HANG >= ALL(SELECT HANG FROM BANGXH 
WHERE VONG = 3 AND NAM = 2009))) OR 
(TD.MACLB2 = (SELECT MACLB 
FROM BANGXH WHERE VONG = 3 AND 
NAM = 2009 AND HANG >= ALL(SELECT HANG FROM BANGXH 
WHERE VONG = 3 AND NAM = 2009))))
SELECT * FROM [D13]
