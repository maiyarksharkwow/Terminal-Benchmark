
#include<iostream>
#include<cmath>
#include<chrono>
#include<iomanip>

  using namespace std;

//Trapezoidal Rule 

double runCal1Integration(long long steps ){
  cout << "[*] DEFINITE INTEGRAL (" << steps << " steps)... " << flush;

  double a = 1.0;
  double b = 50.0;
  double h = (b-a) / steps;
  
  auto start = chrono::high_resolution_clock::now();

  auto f = [](double x){
    return (sin(x) * log(x)) / (1.0+(x * x));
  };

  double total = 0.5 * (f(a) + f(b));
  for (long long i = 1 ; i < steps; ++i){
    double x = a + i * h;
    total += f(x);
  }

  double result = total * h;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = end - start;

  cout << "Done! Time: " << fixed << setprecision(4) << elapsed.count() << "s (Area: " << result << ")" << endl;

  return elapsed.count();

}

double runCal1Derivative(long long steps){
  cout << "[*] DERIVATIVE (" << steps << " steps)... " << flush;

  auto start = chrono::high_resolution_clock::now();

  auto f = [](double x){
    return x * sin(x) * log(x + 1.0);
  };

  double dx = 1e-5;
  double checksum = 0.0;

  for (long long i = 1; i <= steps; ++i){
    double x = 1.0 + (i * 0.00001);
    double derivative = (f(x + dx) - f(x - dx)) / (2.0 * dx);
    checksum += derivative;
  }

  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = end - start;

  cout << "Done! Time:" << fixed << setprecision(4) << elapsed.count() << "s" << endl;

  return elapsed.count();
}

int main(){
  cout << "========================================\n";
  cout << "     TERMINAL BENCHMARK WITH CALCULUS   \n";
  cout << "         by Patiphan Sittikan           \n";
  cout << "========================================\n";

  long long integral_steps = 150'000'000; 
  long long derivative_steps = 50'000'000;
  long long total_steps = integral_steps + derivative_steps;
    
    cout << "[*] Starting Calculus 1 benchmark...\n";
    double t1 = runCal1Integration(integral_steps);
    double t2 = runCal1Derivative(derivative_steps);
    
    double total_time = t1 + t2;
    
    double mega_ints = (double)total_steps / total_time / 1'000'000.0;
    
    cout << "========================================\n";
    cout << " BENCHMARK RESULTS:\n";
    cout << " Total Cal 1 Operations: " << total_steps << " steps\n";
    cout << " Total Time Taken      : " << fixed << setprecision(4) << total_time << " s\n";
    cout << " ---------------------------------------\n";
    cout << " SPEED SCORE           : " << setprecision(2) << mega_ints << " M-ints\n";
    cout << "========================================\n";
    
    return 0;



}
