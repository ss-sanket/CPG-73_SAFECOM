# CPG-73_SAFECOM
Safecom is the capstone project of CPG 73 of TIET pertaining the issues of threats related to communication security in IoT devices that deals with threat detection, mitigation, device scanning and analyzing.
Safecom works with PQC(post quantum cryptography) and DSM(diffie super singular mechanism) to ensure communication security from various threats.
DSM is used because it establish a shared secret key between 2 parties for secret communication over a public network using ECC to generate points and get secret key.
AES is a block cipher mechanism where initial key is used to make many rounds of keys and encryption takes place at each step.
ECC is elliptic curve that uses public key cryptography and it's curve is symmetric to x axis hence it plays a major role in algorithm as a straight line intersects it at 3 points which are our parameters for determining secret key.
we have used various results to compare DSM AES and ECC to determine DSM is better. Some of the comparisons include confidentiality rate and error rate.
After initiating our app, the interface shows various functionalities available from which user can select the course of action, testing was done by having a 3rd party initiate burst attacks which were then solved by our application
