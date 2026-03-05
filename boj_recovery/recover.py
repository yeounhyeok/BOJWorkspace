import os
import re
import requests
from bs4 import BeautifulSoup
from markdownify import markdownify as md_convert
from selenium import webdriver
from selenium.webdriver.firefox.service import Service as FirefoxService
from selenium.webdriver.firefox.options import Options as FirefoxOptions
from webdriver_manager.firefox import GeckoDriverManager

# --- [운혁님 세팅 구간] ---
USER_ID = "yeopeter1031"

PROBLEM_LIST = [
    "1000", "1001", "1002", "1003", "1004", "1005", "1009", "1010", "1011", 
    "1012", "1013", "1015", "1018", "1021", "1022", "1024", "1025", "1026", "1037", 
    "1038", "1041", "1049", "1065", "1068", "1071", "1072", "1074", "1083", "1085", 
    "1107", "1110", "1149", "1152", "1157", "1158", "1167", "1168", "1179", "1181", 
    "1182", "1193", "1197", "1238", "1253", "1260", "1261", "1263", "1264", "1269", 
    "1271", "1316", "1330", "1351", "1354", "1394", "1427", "1436", "1463", "1495", 
    "1504", "1546", "1620", "1629", "1644", "1647", "1654", "1676", "1697", "1717", 
    "1719", "1753", "1759", "1764", "1788", "1806", "1865", "1874", "1904", "1912", 
    "1914", "1916", "1918", "1920", "1922", "1927", "1929", "1931", "1932", "1956", 
    "1958", "1966", "1967", "1976", "1978", "1987", "1991", "2042", "2056", "2075", 
    "2083", "2108", "2110", "2133", "2156", "2164", "2166", "2178", "2193", "2206", 
    "2212", "2239", "2252", "2292", "2293", "2294", "2338", "2343", "2357", "2417", 
    "2438", "2439", "2440", "2444", "2447", "2458", "2467", "2468", "2470", "2473", 
    "2475", "2480", "2491", "2501", "2512", "2525", "2557", "2562", "2563", "2566", 
    "2568", "2577", "2579", "2580", "2581", "2588", "2589", "2606", "2615", "2617", 
    "2630", "2644", "2667", "2675", "2720", "2738", "2739", "2741", "2742", "2743", 
    "2745", "2748", "2749", "2750", "2751", "2753", "2805", "2839", "2869", "2884", 
    "2903", "2908", "2920", "2941", "3003", "3009", "3052", "3863", "4101", "4344", 
    "4386", "4485", "4673", "4779", "4949", "4963", "5073", "5086", "5430", "5543", 
    "5557", "5597", "5622", "5639", "5800", "5953", "5972", "6068", "7562", "7568", 
    "7569", "7576", "7795", "8393", "8958", "9012", "9019", "9063", "9086", "9095", 
    "9214", "9251", "9252", "9372", "9461", "9465", "9498", "9506", "9655", "9656", 
    "9663", "9935", "10026", "10039", "10101", "10171", "10172", "10250", "10425", "10430", 
    "10718", "10757", "10773", "10798", "10807", "10809", "10810", "10811", "10812", "10813", 
    "10814", "10815", "10816", "10817", "10818", "10826", "10828", "10830", "10844", "10845", 
    "10866", "10867", "10869", "10871", "10872", "10886", "10926", "10942", "10950", "10951", 
    "10952", "10988", "10989", "10994", "10997", "10998", "11000", "11005", "11021", "11022", 
    "11047", "11049", "11053", "11054", "11055", "11057", "11279", "11286", "11382", "11399", 
    "11403", "11404", "11444", "11505", "11650", "11651", "11653", "11654", "11657", "11659", 
    "11660", "11718", "11720", "11722", "11723", "11724", "11725", "11726", "11727", "11729", 
    "11779", "11780", "11866", "12015", "12738", "12851", "12865", "13023", "13549", "13913", 
    "14002", "14003", "14215", "14442", "14469", "14500", "14501", "14502", "14503", "14681", 
    "14938", "14940", "15482", "15486", "15552", "15630", "15649", "15650", "15651", "15652", 
    "15654", "15663", "15666", "15681", "15894", "16234", "16236", "16928", "16932", "16933", 
    "16946", "16953", "17219", "17298", "17404", "17478", "18108", "18870", "19951", "20040", 
    "23028", "24262", "24263", "24264", "24265", "24266", "24267", "24313", "24444", "24445", 
    "24479", "24480", "24481", "24482", "24483", "24484", "25083", "25206", "25304", "25305", 
    "25314", "26258", "27323", "27435", "27866", "28278", "29717", "30030", "30805", "30885", "31403"
]

# 경로 설정 (boj_recovery 폴더 안에서 실행 기준)
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
PS_DIR = os.path.join(BASE_DIR, "..", "workspace", "ps")
# ---------------------------

def get_problem_title(prob_id):
    """Solved.ac API를 이용해 문제 번호로 제목을 빠르고 정확하게 가져옵니다."""
    url = f"https://solved.ac/api/v3/problem/show?problemId={prob_id}"
    try:
        response = requests.get(url, headers={"Accept": "application/json"})
        if response.status_code == 200:
            return response.json().get("titleKo", "제목없음")
    except Exception as e:
        print(f"⚠️ {prob_id}번 제목 가져오기 실패: {e}")
    return "제목없음"

def setup_driver():
    firefox_options = FirefoxOptions()
    service = FirefoxService(GeckoDriverManager().install())
    return webdriver.Firefox(service=service, options=firefox_options)

def build_session(driver):
    """Selenium 로그인 후 쿠키를 requests.Session으로 복사"""
    session = requests.Session()
    session.headers.update({"User-Agent": driver.execute_script("return navigator.userAgent")})
    for cookie in driver.get_cookies():
        session.cookies.set(cookie["name"], cookie["value"])
    return session

def get_problem_md(session, prob_id, title):
    """BOJ 문제 페이지를 파싱해서 마크다운으로 반환"""
    try:
        resp = session.get(
            f"https://www.acmicpc.net/problem/{prob_id}",
            timeout=10,
        )
    except Exception as e:
        print(f"    [네트워크 오류] {e}")
        return None

    if resp.status_code != 200:
        print(f"    [HTTP {resp.status_code}] {resp.url}")
        return None

    try:
        soup = BeautifulSoup(resp.text, "html.parser")

        info_tds = soup.select("#problem-info tbody td")
        time_limit   = info_tds[0].text.strip() if len(info_tds) > 0 else "?"
        memory_limit = info_tds[1].text.strip() if len(info_tds) > 1 else "?"

        result = f"# {prob_id}번: {title}\n\n"
        result += f"**시간 제한:** {time_limit} | **메모리 제한:** {memory_limit}\n\n"

        for section_id, section_name in [
            ("problem_description", "문제"),
            ("problem_input",       "입력"),
            ("problem_output",      "출력"),
        ]:
            elem = soup.select_one(f"#{section_id}")
            if elem:
                result += f"## {section_name}\n\n{md_convert(str(elem)).strip()}\n\n"

        i = 1
        while True:
            inp = soup.select_one(f"#sample-input-{i}")
            out = soup.select_one(f"#sample-output-{i}")
            if not inp:
                break
            result += f"## 예제 입력 {i}\n\n```\n{inp.text.strip()}\n```\n\n"
            if out:
                result += f"## 예제 출력 {i}\n\n```\n{out.text.strip()}\n```\n\n"
            i += 1

        return result.strip()
    except Exception as e:
        print(f"    [파싱 오류] {e}")
        return None

def get_solution_id(session, prob_id):
    url = f"https://www.acmicpc.net/status?user_id={USER_ID}&problem_id={prob_id}&result_id=4"
    resp = session.get(url)
    match = re.search(r'href="/source/(\d+)"', resp.text)
    if match:
        return match.group(1)
    return None

def get_source_code(session, sol_id):
    resp = session.get(f"https://www.acmicpc.net/source/download/{sol_id}")
    if resp.status_code == 200 and resp.text.strip():
        return resp.text
    return None

def recover_codes():
    os.makedirs(PS_DIR, exist_ok=True)

    # 로그인 → 세션 구성 (README + cpp 모두 로그인 세션 사용)
    driver = setup_driver()
    try:
        driver.get("https://www.acmicpc.net/login")
        print("💡 브라우저에서 백준 로그인을 완료해 주세요.")
        input("✅ 로그인 완료 후 기차에서 꿀잠 잘 준비가 되었다면 [엔터]를 누르세요...")
        session = build_session(driver)
    finally:
        driver.quit()

    # Phase 1: 기존 폴더 스캔 → README 없으면 세션으로 추가
    print("📋 기존 폴더 README 점검 중...")
    for folder in sorted(os.listdir(PS_DIR)):
        folder_path = os.path.join(PS_DIR, folder)
        if not os.path.isdir(folder_path):
            continue
        readme_path = os.path.join(folder_path, "README.md")
        if os.path.exists(readme_path):
            print(f"  ⏩ {folder} - README 있음, 스킵")
            continue
        num_match = re.match(r'^(\d+)', folder)
        colon_idx = folder.find(': ')
        if not num_match or colon_idx == -1:
            print(f"  ⚠️  {folder} - 번호/제목 추출 실패, 스킵")
            continue
        prob_id = num_match.group(1)
        title = folder[colon_idx + 2:]
        print(f"  📝 {folder} README 없음 → 다운로드 중...")
        problem_md = get_problem_md(session, prob_id, title)
        if problem_md:
            with open(readme_path, "w", encoding="utf-8") as f:
                f.write(problem_md)
            print(f"  ✅ {folder} README 완료!")
        else:
            print(f"  ❌ {folder} README 실패")

    # Phase 2: cpp 없는 문제 복구
    missing = []
    for prob_id in PROBLEM_LIST:
        prob_id = str(prob_id).strip()
        title = get_problem_title(prob_id)
        folder_name = f"{prob_id}번: {title}"
        prob_path = os.path.join(PS_DIR, folder_name)
        file_path = os.path.join(prob_path, f"{folder_name}.cpp")
        if not os.path.exists(file_path):
            missing.append((prob_id, title, folder_name, prob_path, file_path))

    if not missing:
        print("🎯 모든 작업이 완료되었습니다. 여행 잘 다녀오세요!")
        return

    for prob_id, title, folder_name, prob_path, file_path in missing:
        readme_path = os.path.join(prob_path, "README.md")
        print(f"🚀 {folder_name} 복구 시작...")
        try:
            sol_id = get_solution_id(session, prob_id)
            if not sol_id:
                raise Exception("제출 목록에서 솔루션 ID를 찾을 수 없습니다.")

            source_code = get_source_code(session, sol_id)
            if not source_code:
                raise Exception("소스 코드 다운로드 실패")

            os.makedirs(prob_path, exist_ok=True)
            with open(file_path, "w", encoding="utf-8") as f:
                f.write(source_code)

            if not os.path.exists(readme_path):
                problem_md = get_problem_md(session, prob_id, title)
                if problem_md:
                    with open(readme_path, "w", encoding="utf-8") as f:
                        f.write(problem_md)

            print(f"✅ {folder_name} 저장 완료!")

        except Exception as e:
            print(f"❌ {folder_name} 복구 중 오류 발생: {e}")

    print("🎯 모든 작업이 완료되었습니다. 여행 잘 다녀오세요!")

if __name__ == "__main__":
    recover_codes()