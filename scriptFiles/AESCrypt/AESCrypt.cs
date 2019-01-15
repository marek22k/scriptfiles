using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;
using System.Security.Cryptography;

namespace AESCrypt
{
    public class AESCrypt
    {
        public static string Encrypt(string content, string salt, string passwd, int bits)
        {
            try
            {
                AesManaged AES = new AesManaged();
                Rfc2898DeriveBytes rfc = new Rfc2898DeriveBytes(passwd, Encoding.UTF8.GetBytes(salt));
                Byte[] Data = Encoding.UTF8.GetBytes(content);

                AES.BlockSize = 128;
                AES.KeySize = bits;
                AES.Key = rfc.GetBytes(AES.KeySize / 8);
                AES.IV = rfc.GetBytes(AES.BlockSize / 8);

                MemoryStream ms = new MemoryStream();
                CryptoStream cs = new CryptoStream(ms, AES.CreateEncryptor(), CryptoStreamMode.Write);
                cs.Write(Data, 0, Data.Length);
                cs.FlushFinalBlock();
                cs.Close();

                string res = Convert.ToBase64String(ms.ToArray());

                ms.Close();
                AES.Clear();

                return res;
            }
            catch (Exception e)
            {
                return e.Message.ToString();
            }
        }

        public static string Decrypt(string card, string salt, string passwd, int bits)
        {
            try
            {
                AesManaged AES = new AesManaged();
                Rfc2898DeriveBytes rfc = new Rfc2898DeriveBytes(passwd, Encoding.UTF8.GetBytes(salt));
                Byte[] Data = Convert.FromBase64String(card);

                AES.BlockSize = 128;
                AES.KeySize = bits;
                AES.Key = rfc.GetBytes(AES.KeySize / 8);
                AES.IV = rfc.GetBytes(AES.BlockSize / 8);

                MemoryStream ms = new MemoryStream();
                CryptoStream cs = new CryptoStream(ms, AES.CreateDecryptor(), CryptoStreamMode.Write);
                cs.Write(Data, 0, Data.Length);
                cs.FlushFinalBlock();
                cs.Close();

                string res = (string)Encoding.UTF8.GetString(ms.ToArray());

                ms.Close();
                AES.Clear();

                return res;
            }
            catch (Exception e)
            {
                return e.Message.ToString();
            }
        }

        public static string Encrypt(string content, string salt, string passwd, int bits, int overrides, bool output)
        {
            string str = content;
            for (int i = 1; i <= overrides; i++)
            {
                str = Encrypt(str, salt, passwd, bits);
                if (output == true)
                {
                    Console.WriteLine("Result(" + i.ToString() + "): " + str);
                }
            }
            return str;
        }

        public static string Decrypt(string card, string salt, string passwd, int bits, int overrides, bool output)
        {
            string str = card;
            for (int i = 1; i <= overrides; i++)
            {
                str = Decrypt(str, salt, passwd, bits);
                if (output == true)
                {
                    Console.WriteLine("Result(" + i.ToString() + "): " + str);
                }
            }
            return str;
        }
    }
}
