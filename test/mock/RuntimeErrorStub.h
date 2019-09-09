void RuntimeErrorStub_Reset(void);
const char * RuntimeErrorStub_GetLastError(void);
int RuntimeErrorStub_GetLastParameter(void);
void RuntimeError(const char *m, int p, const char *f, int l);
