#pragma once
class Calculate
{
public:
	float D(float**& X, float**& C, int i, int k, int d);
	float update_JUC(float**& U, float**& X, float**& C, int n, int c, int d, float m);
	void update_CK(float**& U, float**& X, float**& C, int d, float m, int n, int k);
	void update_UIK(float**& U, float**& X, float**& C, int d, float m, int c, int i, int k);
	float Dcluster(float**& X, float**& C, int i, int k, int d);
	float Dvector(float**& X, float**& C, int i, int k, int d);
	float MCFCM_update_JUC(float**& U, float**& X, float**& C, int n, int c, int d, float* m);
	void MCFCM_update_CK(float**& U, float**& X, float**& C, int d, float* m, int n, int k);
	void MCFCM_update_UIK(float**& U, float**& X, float**& C, int d, float* m, int c, int i, int k);
};