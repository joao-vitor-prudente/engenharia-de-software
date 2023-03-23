#include <stdio.h>

typedef struct data {
      double w;
      double b;
      double cost;
} Data;

int main(int argc, char const *argv[]) {
      double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
      double y[] = {2.0, 4.0, 6.0, 8.0, 10.0};
      int len = 5;
      double w_init = 0.0;
      double b_init = 0.0;
      double a = 0.01;
      int iterations = 1000;
      Data history[1000];
      Data first = {w_init, b_init, 0};
      history[0] = first;
      for (size_t i = 1; i < iterations; i++) {
            Data *acc = &history[i - 1];
            double sum_w = 0;
            double sum_b = 0;
            double prev_cost = 0;
            for (size_t j = 0; j < len; j++) {
                  sum_w     += (x[j] * acc->w + acc->b - y[j]) * x[j];
                  sum_b     += (x[j] * acc->w + acc->b - y[j]);
                  prev_cost += (x[j] * acc->w + acc->b - y[j])
                             * (x[j] * acc->w + acc->b - y[j]);
            }
            prev_cost /= 2 * len;
            acc->cost = prev_cost;
            double new_w = acc->w - a * sum_w / len;
            double new_b = acc->b - a * sum_b / len;
            Data cur = {new_w, new_b, 0};
            history[i] = cur;
      }
      double last_w = history[iterations - 1].w;
      double last_b = history[iterations - 1].b;
      double last_cost = history[iterations - 1].cost;
      for (size_t j = 0; j < len; j++) {
            last_cost += (x[j] * last_w + last_b - y[j]) 
                       * (x[j] * last_w + last_b - y[j]);
      }
      history[iterations - 1].cost = last_cost;
      for (size_t i = 0; i < iterations; i++) {
            printf("w: %f; b: %f; cost: %f\n", 
                  history[i].w, history[i].b, history[i].cost);
      }      
      return 0;
}