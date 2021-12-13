#include <iostream>

// using namespace std;

class phu_nu
{
	// Encapsulation ( đóng gói )
public:
	phu_nu()
	{ // constructor
	}

	phu_nu(const std::string &ht, bool z = true)
		: ho_ten(ht), con_zin(z) // cach khoi tao gia tri nhanh. khong can phai gan nhu ben duoi
	// dùng tham chiếu để tránh việc sao chép dữ liệu  ( dùng luôn chính input đầu vào gốc) => có nguy cơ thay đổi dữ liệu gốc ==> phai có const ở phía trước kiểu dũ liệu
	{
		// ho_ten = ht;
		// con_zin = z;
	}
	~phu_nu()
	{ // được gọi khi đối tượng bị hủy thông qua từ khóa delete
		std::cout << "goodbye" << ho_ten << std::endl;
	}
	void trang_diem(){

	};
	// polymophism ( đa hình)
	virtual std::string choi_nhac_cu(std::string nhac_cu) // từ khóa virtural : khi có một lớp dẫn xuất ( lớp con ) gọi đến method gặp từ khóa virtual thì sẽ chạy method đó ( được override ) ở lớp con. Nếu chưa được override thì sẽ chạy method ở lớp cơ sở ( lớp cha )
	{
		return "Ken";
	}

	// abstraction: cung cấp cho một cơ chế. phương thức để có thể can thiệp vào để sửa đổi dữ liệu ( khác getter,setter )
	void va_zin()
	{
		con_zin = true;
	}
	void show_hang()
	{
		std::cout << ho_ten << " " << (con_zin ? "con zin" : "mat zin") << std::endl;
	}

protected:
	std::string ho_ten;
	bool con_zin;
};

// INHERITANCE (  Kế thừa )
class gai_ngoan : public phu_nu
{
public:
	gai_ngoan(const std::string &ht, int t, bool z = true)
		: phu_nu(ht, z), tuoi(t) // gọi lại constructor của lớp basic , cần truyền đúng tham số như ở constructor của lớp basisc
	{
	}
	void quetnha()
	{
		std::cout << ho_ten << "đang quet nha" << std::endl;
	}
	std::string choi_nhac_cu(std::string nhac_cu)
	{

		return "Trong";
	}

private:
	int tuoi;
};

class gai_hu : public phu_nu
{
public:
	gai_hu(const std::string &ht, int t, bool z = true)
		: phu_nu(ht, z), tuoi(t) // gọi lại constructor của lớp basic , cần truyền đúng tham số như ở constructor của lớp basisc
	{
	}
	void dibar()
	{
		std::cout << "di bar" << std::endl;
	}
	std::string choi_nhac_cu(std::string nhac_cu)
	{

		return "Sao";
	}

private:
	int tuoi;
};
int main()
{
	phu_nu thao; // biến cấp phát tĩnh, cuối chương trình tự động hủy -> gọi hàm hủy

	phu_nu *marria = new phu_nu("marria");
	phu_nu *someone = new phu_nu;

	std::cout << marria->choi_nhac_cu("ken") << std::endl;
	marria->va_zin();
	marria->show_hang();
    
	std::cout<<"gai ngoan -----------------------------------------"<< std::endl ;


	gai_ngoan *thino = new gai_ngoan("trung kien", 19); // constructor phải được định nghĩa lại. lớp dẫn xuất không thể kế thừa được contructor của lớp basic
	thino->show_hang();
	thino->quetnha();

	// polymorphism
	gai_hu *ngoctrinh = new gai_hu("Ngoc trinh", 25);
	std::cout << thino->choi_nhac_cu("abc") << std::endl;
	std::cout << ngoctrinh->choi_nhac_cu("abc") << std::endl;

	// special  ( con trỏ đa hình )

    std::cout<< "new line ----------------------------------------------" << std::endl;

	
	phu_nu *gaigoi = new gai_hu("tran duy hung", 25, false);
	std::cout << gaigoi->choi_nhac_cu("abc") << std::endl; // goi method lop dan xuat
	system("pause");
	return 0;
}