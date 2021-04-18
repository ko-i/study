enum Ordering {
    Less,
    Equal,
    Greater,
}

trait PartialOrd<Rhs = Self>: PartialEq<Rhs> where Rhs: ?Sized {
    fn partial_cmp(&self, other: &Rhs) -> Option<Ordering>;

    fn lt(&self, other: &Rhs) -> bool {...}
    fn le(&self, other: &Rhs) -> bool {...}
    fn gt(&self, other: &Rhs) -> bool {...}
    fn ge(&self, other: &Rhs) -> bool {...}
}