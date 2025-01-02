from typing import List
from pyperclip import copy


def ref_email(hr_name: str, company_name: str, job_ids: List[str]) -> str:
    print("Title: Subject: Referral Request @Company | Frontend Developer (2 years)\n")

    ref_str = f"""
Hi {hr_name},
Hope you're doing well.

Will keep it brief to respect your time.
- Role: Frontend Developer
- Experience: 2 years
- Current Employer: Carwale
- Previous Employers: Carwale
- Location: Mumbai
- Notice Period: Serving Notice Period
- Last Working Day: January 17
- Open to Relocation: Yes (Bangalore & Pune)
- Job ID:  {[job_id for job_id in job_ids]}

Would love to hear if there are any suitable openings at [Company] that align with my experience and skills.

PFA, latest resume.
Thanks for your time and consideration!

Best regards,
Kailas Mahavarkar
kailashmahavarkar5@gmail.com
+91 9920962195"""

    copy(ref_str)
    return ref_str


x = ref_email(
    hr_name="Pooja",
    company_name="Myntra",
    job_ids=[]
)
print(x)
