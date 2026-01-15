#include "Point.hpp"

// Returns the signed z-component of (AB × AP)
Fixed get_cross_product_ab_x_ap_z_component(const Point &a, const Point &b, const Point &p) {
	Fixed vec_ab_x = b.getX() - a.getX();
	Fixed vec_ab_y = b.getY() - a.getY();

	Fixed vec_ap_x = p.getX() - a.getX();
	Fixed vec_ap_y = p.getY() - a.getY();

	Fixed cross_product = vec_ab_x * vec_ap_y - vec_ab_y * vec_ap_x;

	return (cross_product);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed cross_a = get_cross_product_ab_x_ap_z_component(a, b, point);
	Fixed cross_b = get_cross_product_ab_x_ap_z_component(b, c, point);
	Fixed cross_c = get_cross_product_ab_x_ap_z_component(c, a, point);

	if ((cross_a > 0 && cross_b > 0 && cross_c > 0) || (cross_a < 0 && cross_b < 0 && cross_c < 0)) {
		return true;
	} else {
		return false;
	}
}
