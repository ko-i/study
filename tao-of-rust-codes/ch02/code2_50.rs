fn main() {
    #[derive(Debug, PartialEq)]
    struct Point {
        x: f64,
        y: f64,
    }

    let box_point = Box::new(Point {x: 0.0, y: 0.0});
    // let unboxed_point: Point = *box_point;
    println!("{:?}", *box_point);
    // assert_eq!(unboxed_point, Point {x: 0.0, y: 0.0});
    assert_eq!(*box_point, Point {x: 0.0, y: 0.0});
}