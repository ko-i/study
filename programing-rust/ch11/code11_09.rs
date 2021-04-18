fn dot1(v1: &[i64], v2: &[i64]) -> i64 {
    let mut total = 0;

    for i in 0 .. v1.len() {
        total = total + v1[i] * v2[i];
    }

    total
}

fn dot2<N>(v1: &[N], v2: &[N]) -> N {
    let mut total: N = 0;

    for i in 0 .. v1.len() {
        total = total + v1[i] * v2[i];
    }

    total
}

use std::ops::{Add, Mul};

fn dot3<N: Add + Mul + Default>(v1: &[N], v2: &[N]) -> N {
    let mut total: N = N::default();

    for i in 0 .. v1.len() {
        total = total + v1[i] * v2[i];
    }

    total
}

fn dot4<N: Add<Output = N> + Mul<Output = N> + Default>(v1: &[N], v2: &[N]) -> N {

}

fn dot5<N>(v1: &[N], v2: &[N]) -> N where N: Add<Output = N> + Mul<Output = N> + Default {

}

fn dot6<N>(v1: &[N], v2: &[N]) -> N where N: Add<Output = N> + Mul<Output = N> + Default + Copy {
    let mut total = N::default();

    for i in 0 .. v1.len() {
        total = total + v1[i] * v2[i];
    }

    total
}